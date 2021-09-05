#include "DrawVisitor.hpp"

#include <Shapes/Canvas.hpp>
#include <Shapes/Line.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Rectangle.hpp>
#include <Shapes/Circle.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Diamond.hpp>
#include <Shapes/Polygon.hpp>

#include <Utils/Constants.hpp>

#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/matx.hpp>    // cv::Vec4b
#include <opencv2/core/mat.hpp>     // cv::Mat

#include <algorithm>
#include <queue>                    // std::queue
#include <stdexcept>                // std::invalid_argument
#include <string>                   // std::string
#include <vector>                   // std::vector

static inline cv::Vec4b ColorToVec4b(const MiniCAD::Color &c)
{
    // OpenCV uses BGRA format
    return cv::Vec4b(c.b, c.g, c.r, c.a);
}

static inline bool IsInside(const cv::Mat &image, int x, int y)
{
    return (0 <= y) && (y < image.rows) && (0 <= x) && (x < image.cols);
}

static cv::Vec4b GetPixel(cv::Mat &image, int x, int y)
{
    if (IsInside(image, x, y))
    {
        return image.at<cv::Vec4b>(y, x);
    }
    return cv::Vec4b();
}

static void PutPixel(cv::Mat &image, int x, int y, const cv::Vec4b &color)
{
    // Input file and OpenCV have different coordinate systems
    // Interchanging x and y is mandatory
    if (IsInside(image, x, y))
    {
        image.at<cv::Vec4b>(y, x) = color;
    }
}

static void PutPixelsIn8PartsAroundCircleCenter(cv::Mat &image, int x_circle, int y_circle,
                                                int x, int y, const cv::Vec4b &color)
{
    int add_to_x[] = { +x, -x, +x, -x, +y, -y, +y, -y };
    int add_to_y[] = { +y, +y, -y, -y, +x, +x, -x, -x };
    for (int i = 0; i < 8; ++i)
    {
        PutPixel(image, x_circle + add_to_x[i], y_circle + add_to_y[i], color);
    }
}

static MiniCAD::Point GetCenterOfMass(const std::vector<MiniCAD::Point> &points)
{
    MiniCAD::Point center(0, 0);

    for (MiniCAD::Point p : points)
    {
        center.x += p.x;
        center.y += p.y;
    }

    center.x /= points.size();
    center.y /= points.size();
    return center;
}

namespace MiniCAD
{
    DrawVisitor::DrawVisitor()
    {

    }

    DrawVisitor::~DrawVisitor()
    {

    }

    void DrawVisitor::Visit(const Canvas &canvas)
    {
        image = cv::Mat(canvas.GetHeight(), canvas.GetWidth(), CV_8UC4,
                        ColorToVec4b(canvas.GetColor()));
    }

    void DrawVisitor::Visit(const Line &line)
    {
        cv::Scalar color = ColorToVec4b(line.GetColor());
        // Generalized Integer Bresenham's Algorithm for all quadrants
        // Stolen from https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
        int x0 = line.GetP0().x;
        int y0 = line.GetP0().y;
        int x1 = line.GetP1().x;
        int y1 = line.GetP1().y;

        int dx = std::abs(x1 - x0);
        int sx = x0 < x1 ? 1 : -1;
        int dy = -std::abs(y1 - y0);
        int sy = y0 < y1 ? 1 : -1; 
        int err = dx + dy;

        while (true)
        {
            PutPixel(image, x0, y0, color);

            if (x0 == x1 && y0 == y1)
            {
                break;
            }

            int e2 = 2 * err;
            if (e2 >= dy)
            {
                err += dy;
                x0 += sx;
            }
            if (e2 <= dx)
            {
                err += dx;
                y0 += sy;
            }
        }
    }

    void DrawVisitor::Visit(const Square &square)
    {
        Visit(Rectangle(square.GetTopLeftPoint(), square.GetSide(), square.GetSide(),
                        square.GetOutlineColor(), square.GetFillColor()));
    }

    void DrawVisitor::Visit(Rectangle const& rectangle)
    {
        int x_start = rectangle.GetTopLeftPoint().x;
        int y_start = rectangle.GetTopLeftPoint().y;
        int x_end = x_start + rectangle.GetWidth();
        int y_end = y_start + rectangle.GetHeight();

        for (int x = x_start; x <= x_end; ++x)
        {
            for (int y = y_start; y <= y_end; ++y)
            {
                Color c = (x == x_start) || (x == x_end) || (y == y_start) || (y == y_end)
                          ? rectangle.GetOutlineColor()
                          : rectangle.GetFillColor();

                PutPixel(image, x, y, ColorToVec4b(c));
            }
        }
    }

    void DrawVisitor::Visit(const Circle &circle)
    {
        // Circle generation using Brasenham's algorithm
        // https://www.geeksforgeeks.org/bresenhams-circle-drawing-algorithm/
        int xc = circle.GetCenterPoint().x;
        int yc = circle.GetCenterPoint().y;
        int x = 0;
        int y = circle.GetRadius();
        int d = 3 - 2 * circle.GetRadius();

        while (y >= x)
        {
            PutPixelsIn8PartsAroundCircleCenter(image, xc, yc, x, y,
                                                ColorToVec4b(circle.GetOutlineColor()));

            ++x;
            if (d > 0)
            {
                --y;
                d += 4 * (x - y) + 10;
            }
            else
            {
                d += 4 * x + 6;
            }
        }

        FloodFill(xc, yc, ColorToVec4b(circle.GetOutlineColor()),
                  ColorToVec4b(circle.GetFillColor()));
    }

    void DrawVisitor::Visit(const Triangle &triangle)
    {
        Point p0 = triangle.GetP0();
        Point p1 = triangle.GetP1();
        Point p2 = triangle.GetP2();
        std::vector<Point> points = { p0, p1, p2 };

        Visit(Polygon(points, triangle.GetOutlineColor(), triangle.GetFillColor()));
    }

    void DrawVisitor::Visit(const Diamond &diamond)
    {
        Point p0 = diamond.GetCenterPoint();
        p0.x -= diamond.GetHorizontalDiagonal() / 2;
        Point p1 = diamond.GetCenterPoint();
        p1.y -= diamond.GetVerticalDiagonal() / 2;
        Point p2 = diamond.GetCenterPoint();
        p2.x += diamond.GetHorizontalDiagonal() / 2;
        Point p3 = diamond.GetCenterPoint();
        p3.y += diamond.GetVerticalDiagonal() / 2;
        std::vector<Point> points = { p0, p1, p2, p3 };

        Visit(Polygon(points, diamond.GetOutlineColor(), diamond.GetFillColor()));
    }

    void DrawVisitor::Visit(const Polygon &polygon)
    {
        std::vector<Point> points = polygon.GetPoints();
        Color c = polygon.GetOutlineColor();

        for (decltype(points.size()) point_index = 0; point_index < points.size(); ++point_index)
        {
            Point p0 = points[point_index];
            Point p1 = points[(point_index + 1) % points.size()];
            Visit(Line(p0, p1, c));
        }
        Point center = GetCenterOfMass(points);

        FloodFill(center.x, center.y, ColorToVec4b(polygon.GetOutlineColor()),
                  ColorToVec4b(polygon.GetFillColor()));
    }

    void DrawVisitor::WriteImage(const std::string &fileName)
    {
        cv::imwrite(fileName, image);
    }

    void DrawVisitor::FloodFill(int x_start, int y_start,
                                const cv::Vec4b &outline_color,
                                const cv::Vec4b &fill_color
    )
    {
        if (!IsInside(image, x_start, y_start))
        {
            throw std::invalid_argument(ErrorMessages::InvalidFillStartingPoint);
        }

        std::queue<Cell> cell_queue;
        cell_queue.push(Cell(x_start, y_start));

        std::vector<std::vector<bool>> visited(image.cols,
                                               std::vector<bool>(image.rows, false));

        while (!cell_queue.empty())
        {
            Cell cell = cell_queue.front();
            cell_queue.pop();

            if (visited[cell.x][cell.y])
            {
                continue;
            }

            visited[cell.x][cell.y] = true;

            PutPixel(image, cell.x, cell.y, fill_color);

            Cell neighbors[] = { Cell(cell.x + 1, cell.y),
                                 Cell(cell.x - 1, cell.y),
                                 Cell(cell.x, cell.y + 1),
                                 Cell(cell.x, cell.y - 1) };

            for (const Cell &neighbor : neighbors)
            {
                if (IsInside(image, neighbor.x, neighbor.y)
                    && (GetPixel(image, neighbor.x, neighbor.y) != outline_color))
                {
                    cell_queue.push(neighbor);
                }
            }
        }
    }
}

