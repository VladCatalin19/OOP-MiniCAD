#include "ShapeFactory.hpp"

#include <Shapes/Shape.hpp>
#include <Shapes/Canvas.hpp>
#include <Shapes/Line.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Rectangle.hpp>
#include <Shapes/Circle.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Diamond.hpp>
#include <Shapes/Polygon.hpp>

#include <Utils/Constants.hpp>

#include <cstdlib>
#include <stdexcept>
#include <sstream>              // std::stringstream
#include <string>               // std::string
#include <vector>               // std::vector

static MiniCAD::Color ParseColor(const std::string &rgb, const std::string &alpha)
{
    unsigned long n = std::stoul(rgb.substr(1, rgb.size() - 1), nullptr, 16);

    unsigned char r = (n & 0xFF0000) >> 16;
    unsigned char g = (n & 0x00FF00) >> 8;
    unsigned char b = n & 0x0000FF;
    unsigned char a = std::stoi(alpha);
    return MiniCAD::Color(r, g, b, a);
}

static MiniCAD::Canvas* CreateCanvas(const std::vector<std::string> &line_split)
{
    MiniCAD::Canvas *canvas = nullptr;

    try
    {
        int height = std::stoi(line_split[1]);
        int width = std::stoi(line_split[2]);
        MiniCAD::Color color = ParseColor(line_split[3], line_split[4]);
        canvas = new MiniCAD::Canvas(height, width, color);
    }
    catch (...)
    {
        return nullptr;
    }

    return canvas;
}

static MiniCAD::Line* CreateLine(const std::vector<std::string> &line_split)
{
    MiniCAD::Line *line = nullptr;

    try
    {
        MiniCAD::Point p0 = MiniCAD::Point(std::stoi(line_split[1]), std::stoi(line_split[2]));
        MiniCAD::Point p1 = MiniCAD::Point(std::stoi(line_split[3]), std::stoi(line_split[4]));
        MiniCAD::Color color = ParseColor(line_split[5], line_split[6]);
        line = new MiniCAD::Line(p0, p1, color);
    }
    catch (...)
    {
        return nullptr;
    }

    return line;
}

static MiniCAD::Square* CreateSquare(const std::vector<std::string> &line_split)
{
    MiniCAD::Square *square = nullptr;

    try
    {
        MiniCAD::Point top_left = MiniCAD::Point(std::stoi(line_split[1]), std::stoi(line_split[2]));
        int side = std::stoi(line_split[3]);
        MiniCAD::Color outline_color = ParseColor(line_split[4], line_split[5]);
        MiniCAD::Color fill_color = ParseColor(line_split[6], line_split[7]);
        square = new MiniCAD::Square(top_left, side, outline_color, fill_color);
    }
    catch (...)
    {
        return nullptr;
    }

    return square;
}

static MiniCAD::Rectangle* CreateRectangle(const std::vector<std::string> &line_split)
{
    MiniCAD::Rectangle *rectangle = nullptr;

    try
    {
        MiniCAD::Point top_left = MiniCAD::Point(std::stoi(line_split[1]), std::stoi(line_split[2]));
        int height = std::stoi(line_split[3]);
        int width = std::stoi(line_split[4]);
        MiniCAD::Color outline_color = ParseColor(line_split[5], line_split[6]);
        MiniCAD::Color fill_color = ParseColor(line_split[7], line_split[8]);
        rectangle = new MiniCAD::Rectangle(top_left, height, width, outline_color, fill_color);
    }
    catch (...)
    {
        return nullptr;
    }

    return rectangle;
}

static MiniCAD::Circle* CreateCircle(const std::vector<std::string> &line_split)
{
    MiniCAD::Circle *circle = nullptr;

    try
    {
        MiniCAD::Point center = MiniCAD::Point(std::stoi(line_split[1]), std::stoi(line_split[2]));
        int radius = std::stoi(line_split[3]);
        MiniCAD::Color outline_color = ParseColor(line_split[4], line_split[5]);
        MiniCAD::Color fill_color = ParseColor(line_split[6], line_split[7]);
        circle = new MiniCAD::Circle(center, radius, outline_color, fill_color);
    }
    catch (...)
    {
        return nullptr;
    }

    return circle;
}

static MiniCAD::Triangle* CreateTriangle(const std::vector<std::string> &line_split)
{
    MiniCAD::Triangle *triangle = nullptr;

    try
    {
        MiniCAD::Point p0 = MiniCAD::Point(std::stoi(line_split[1]), std::stoi(line_split[2]));
        MiniCAD::Point p1 = MiniCAD::Point(std::stoi(line_split[3]), std::stoi(line_split[4]));
        MiniCAD::Point p2 = MiniCAD::Point(std::stoi(line_split[5]), std::stoi(line_split[6]));
        MiniCAD::Color outline_color = ParseColor(line_split[7], line_split[8]);
        MiniCAD::Color fill_color = ParseColor(line_split[9], line_split[10]);
        triangle = new MiniCAD::Triangle(p0, p1, p2, outline_color, fill_color);
    }
    catch (...)
    {
        return nullptr;
    }

    return triangle;
}

static MiniCAD::Diamond* CreateDiamond(const std::vector<std::string> &line_split)
{
    MiniCAD::Diamond *diamond = nullptr;

    try
    {
        MiniCAD::Point center = MiniCAD::Point(std::stoi(line_split[1]), std::stoi(line_split[2]));
        int horiz_diag = std::stoi(line_split[3]);
        int vert_diag = std::stoi(line_split[4]);
        MiniCAD::Color outline_color = ParseColor(line_split[5], line_split[6]);
        MiniCAD::Color fill_color = ParseColor(line_split[7], line_split[8]);
        diamond = new MiniCAD::Diamond(center, horiz_diag, vert_diag, outline_color, fill_color);
    }
    catch (...)
    {
        return nullptr;
    }

    return diamond;
}

static MiniCAD::Polygon* CreatePolygon(const std::vector<std::string> &line_split)
{
    MiniCAD::Polygon *polygon = nullptr;

    try
    {
        std::vector<MiniCAD::Point> points = std::vector<MiniCAD::Point>();
        int points_num = std::stoi(line_split[1]);

        points.reserve(points_num);
        for (int i = 2; i < static_cast<int>(line_split.size()) - 4; i += 2)
        {
            MiniCAD::Point p = MiniCAD::Point(std::stoi(line_split[i]), std::stoi(line_split[i + 1]));
            points.push_back(p);
        }

        int col_idx = line_split.size() - 4;
        MiniCAD::Color outline_color = ParseColor(line_split[col_idx], line_split[col_idx + 1]);
        MiniCAD::Color fill_color = ParseColor(line_split[col_idx + 2], line_split[col_idx + 3]);

        polygon = new MiniCAD::Polygon(points, outline_color, fill_color);
    }
    catch (...)
    {
        return nullptr;
    }

    return polygon;
}

static std::vector<std::string> SplitString(const std::string &str, char delim)
{
    std::stringstream ss(str);
    std::vector<std::string> split = std::vector<std::string>();
    std::string token;

    while (std::getline(ss, token, delim))
    {
        split.push_back(token);
    }
    return split;
}

namespace MiniCAD
{
    Shape *ShapeFactory::CreateShape(const std::string &line) const
    {
        Shape *shape = nullptr;
        std::vector<std::string> line_splits = SplitString(line, LineProperties::Delimitator);

        if (line_splits.size() == 0)
        {
            return nullptr;
        }

        if (line_splits[0].compare(ShapeNames::Canvas) == 0)
        {
            shape = CreateCanvas(line_splits);
        }
        else if (line_splits[0].compare(ShapeNames::Line) == 0)
        {
            shape = CreateLine(line_splits);
        }
        else if (line_splits[0].compare(ShapeNames::Square) == 0)
        {
            shape = CreateSquare(line_splits);
        }
        else if (line_splits[0].compare(ShapeNames::Rectangle) == 0)
        {
            shape = CreateRectangle(line_splits);
        }
        else if (line_splits[0].compare(ShapeNames::Circle) == 0)
        {
            shape = CreateCircle(line_splits);
        }
        else if (line_splits[0].compare(ShapeNames::Triangle) == 0)
        {
            shape = CreateTriangle(line_splits);
        }
        else if (line_splits[0].compare(ShapeNames::Diamond) == 0)
        {
            shape = CreateDiamond(line_splits);
        }
        else if (line_splits[0].compare(ShapeNames::Polygon) == 0)
        {
            shape = CreatePolygon(line_splits);
        }

        return shape;
    }
}
