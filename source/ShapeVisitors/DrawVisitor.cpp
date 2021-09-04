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

#include <opencv2/core/matx.hpp>
#include <opencv2/imgcodecs.hpp>
#include <queue>
#include <stdexcept>
#include <vector>
#include <algorithm>

DrawVisitor::DrawVisitor()
{

}

DrawVisitor::~DrawVisitor()
{

}

static inline cv::Vec4b ColorToVec4b(Color const& c)
{
    // OpenCV uses BGRA format
    return cv::Vec4b(c.b, c.g, c.r, c.a);
}

static inline bool IsInside(cv::Mat const& image, int x, int y)
{
    return 0 <= y && y < image.rows && 0 <= x && x < image.cols;
}

static cv::Vec4b GetPixel(cv::Mat& image, int x, int y)
{
    if (IsInside(image, x, y))
    {
        return image.at<cv::Vec4b>(y, x);
    }
    return cv::Vec4b();
}

static void PutPixel(cv::Mat& image, int x, int y, cv::Vec4b const& color)
{
    // Input file and OpenCV have different coordinate systems
    // Interchanging x and y is mandatory
    if (IsInside(image, x, y))
    {
        image.at<cv::Vec4b>(y, x) = color;
    }
}

static void PutPixelsIn8PartsAroundCircleCenter(
    cv::Mat& image, int xCircle, int yCircle, int x, int y, cv::Vec4b color
)
{
    int addToX[] = { +x, -x, +x, -x, +y, -y, +y, -y };
    int addToY[] = { +y, +y, -y, -y, +x, +x, -x, -x };
    for (int i = 0; i < 8; ++i)
    {
        PutPixel(image, xCircle + addToX[i], yCircle + addToY[i], color);
    }
}

void DrawVisitor::Visit(Canvas const& canvas)
{
    image = cv::Mat(
        canvas.GetHeight(), canvas.GetWidth(), CV_8UC4,
        ColorToVec4b(canvas.GetColor())
    );
}

void DrawVisitor::Visit(Line const& line)
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

void DrawVisitor::Visit(Square const& square)
{
    Visit(Rectangle(square.GetTopLeftPoint(), square.GetSide(), square.GetSide(),
        square.GetOutlineColor(), square.GetFillColor())
    );
}

void DrawVisitor::Visit(Rectangle const& rectangle)
{
    int xStart = rectangle.GetTopLeftPoint().x;
    int yStart = rectangle.GetTopLeftPoint().y;
    int xEnd = xStart + rectangle.GetWidth();
    int yEnd = yStart + rectangle.GetHeight();

    for (int x = xStart; x <= xEnd; ++x)
    {
        for (int y = yStart; y <= yEnd; ++y)
        {
            Color c = x == xStart || x == xEnd || y == yStart || y == yEnd
                ? rectangle.GetOutlineColor() : rectangle.GetFillColor();

            PutPixel(image, x, y, ColorToVec4b(c));
        }
    }
}

void DrawVisitor::Visit(Circle const& circle)
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

    FloodFill(
        xc, yc, ColorToVec4b(circle.GetOutlineColor()),
        ColorToVec4b(circle.GetFillColor())
    );
}

void DrawVisitor::Visit(Triangle const& triangle)
{
    Point p0 = triangle.GetP0();
    Point p1 = triangle.GetP1();
    Point p2 = triangle.GetP2();
    std::vector<Point> points = { p0, p1, p2 };

    Visit(Polygon(points, triangle.GetOutlineColor(), triangle.GetFillColor()));
}

void DrawVisitor::Visit(Diamond const& diamond)
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

static Point GetCenterOfMass(std::vector<Point> const& points)
{
    Point center(0, 0);

    for (Point p : points)
    {
        center.x += p.x;
        center.y += p.y;
    }

    center.x /= points.size();
    center.y /= points.size();
    return center;
}

void DrawVisitor::Visit(Polygon const& polygon)
{
    std::vector<Point> points = polygon.GetPoints();
    Color c = polygon.GetOutlineColor();

    int pointsSize = static_cast<int>(points.size());
    for (int i = 0; i < pointsSize; ++i)
    {
        Point p0 = points[i];
        Point p1 = points[(i + 1) % pointsSize];
        Visit(Line(p0, p1, c));
    }
    Point center = GetCenterOfMass(points);

    FloodFill(
        center.x, center.y, ColorToVec4b(polygon.GetOutlineColor()),
        ColorToVec4b(polygon.GetFillColor())
    );
}

void DrawVisitor::WriteImage(std::string const& fileName)
{
    cv::imwrite(fileName, image);
}

void DrawVisitor::FloodFill(
    int xStart, int yStart, cv::Vec4b const& outlineColor,
    cv::Vec4b const& fillColor
)
{
    if (!IsInside(image, xStart, yStart))
    {
        throw std::invalid_argument(ErrorMessages::InvalidFillStartingPoint);
    }

    std::queue<Cell> q;
    q.push(Cell(xStart, yStart));

    std::vector<std::vector<bool>> visited(
        image.cols, std::vector<bool>(image.rows, false)
    );

    while (!q.empty())
    {
        Cell cell = q.front();
        q.pop();

        if (visited[cell.x][cell.y])
        {
            continue;
        }

        visited[cell.x][cell.y] = true;

        PutPixel(image, cell.x, cell.y, fillColor);

        Cell neighbors[] =
        {
            Cell(cell.x + 1, cell.y),
            Cell(cell.x - 1, cell.y),
            Cell(cell.x, cell.y + 1),
            Cell(cell.x, cell.y - 1)
        };

        for (Cell neighbor : neighbors)
        {
            if (IsInside(image, neighbor.x, neighbor.y)
                && GetPixel(image, neighbor.x, neighbor.y) != outlineColor)
            {
                q.push(neighbor);
            }
        }
    }
}
