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

#include <cstdint>              // std::uint8_t
#include <memory>               // std::unique_ptr
#include <stdexcept>            // std::invalid_argument, std::out_of_range, std::bad_alloc
#include <sstream>              // std::stringstream
#include <string>               // std::string, std::stoul, std::stoi, std::getline
#include <vector>               // std::vector, std::size_t

// Can throw std::invalid_argument and std::out_of_range
static MiniCAD::Point ParsePoint(const std::string &x, const std::string &y)
{
    std::uint8_t x_ = static_cast<std::uint8_t>(std::stoi(x));
    std::uint8_t y_ = static_cast<std::uint8_t>(std::stoi(y));
    return MiniCAD::Point(x_, y_);
}

// Can throw std::invalid_argument and std::out_of_range
static MiniCAD::Color ParseColor(const std::string &rgb, const std::string &alpha)
{
    unsigned long n = std::stoul(rgb.substr(1, rgb.size() - 1), nullptr, 16);

    std::uint8_t r = static_cast<std::uint8_t>((n & 0xff'00'00UL) >> 16);
    std::uint8_t g = static_cast<std::uint8_t>((n & 0x00'ff'00UL) >> 8);
    std::uint8_t b = static_cast<std::uint8_t>(n & 0x00'00'ffUL);
    std::uint8_t a = static_cast<std::uint8_t>(std::stoi(alpha));

    return MiniCAD::Color(r, g, b, a);
}

static std::unique_ptr<MiniCAD::Canvas> CreateCanvas(const std::vector<std::string> &line_split)
{
    MiniCAD::Canvas *canvas = nullptr;

    try
    {
        int height = std::stoi(line_split.at(1));
        int width = std::stoi(line_split.at(2));
        MiniCAD::Color color = ParseColor(line_split.at(3), line_split.at(4));
        canvas = new MiniCAD::Canvas(height, width, color);
    }
    catch (const std::invalid_argument &)
    {
        canvas = nullptr;
    }
    catch (const std::out_of_range &)
    {
        canvas = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        canvas = nullptr;
    }

    return std::unique_ptr<MiniCAD::Canvas>(canvas);
}

static std::unique_ptr<MiniCAD::Line> CreateLine(const std::vector<std::string> &line_split)
{
    MiniCAD::Line *line = nullptr;

    try
    {
        MiniCAD::Point p0 = ParsePoint(line_split.at(1), line_split.at(2));
        MiniCAD::Point p1 = ParsePoint(line_split.at(3), line_split.at(4));
        MiniCAD::Color color = ParseColor(line_split.at(5), line_split.at(6));
        line = new MiniCAD::Line(p0, p1, color);
    }
    catch (const std::invalid_argument &)
    {
        line = nullptr;
    }
    catch (const std::out_of_range &)
    {
        line = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        line = nullptr;
    }

    return std::unique_ptr<MiniCAD::Line>(line);
}

static std::unique_ptr<MiniCAD::Square> CreateSquare(const std::vector<std::string> &line_split)
{
    MiniCAD::Square *square = nullptr;

    try
    {
        MiniCAD::Point top_left = ParsePoint(line_split.at(1), line_split.at(2));
        int side = std::stoi(line_split.at(3));
        MiniCAD::Color outline_color = ParseColor(line_split.at(4), line_split.at(5));
        MiniCAD::Color fill_color = ParseColor(line_split.at(6), line_split.at(7));
        square = new MiniCAD::Square(top_left, side, outline_color, fill_color);
    }
    catch (const std::invalid_argument &)
    {
        square = nullptr;
    }
    catch (const std::out_of_range &)
    {
        square = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        square = nullptr;
    }

    return std::unique_ptr<MiniCAD::Square>(square);
}

static std::unique_ptr<MiniCAD::Rectangle> CreateRectangle(const std::vector<std::string> &line_split)
{
    MiniCAD::Rectangle *rectangle = nullptr;

    try
    {
        MiniCAD::Point top_left = ParsePoint(line_split.at(1), line_split.at(2));
        int height = std::stoi(line_split.at(3));
        int width = std::stoi(line_split.at(4));
        MiniCAD::Color outline_color = ParseColor(line_split.at(5), line_split.at(6));
        MiniCAD::Color fill_color = ParseColor(line_split.at(7), line_split.at(8));
        rectangle = new MiniCAD::Rectangle(top_left, height, width, outline_color, fill_color);
    }
    catch (const std::invalid_argument &)
    {
        rectangle = nullptr;
    }
    catch (const std::out_of_range &)
    {
        rectangle = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        rectangle = nullptr;
    }

    return std::unique_ptr<MiniCAD::Rectangle>(rectangle);
}

static std::unique_ptr<MiniCAD::Circle> CreateCircle(const std::vector<std::string> &line_split)
{
    MiniCAD::Circle *circle = nullptr;

    try
    {
        MiniCAD::Point center = ParsePoint(line_split.at(1), line_split.at(2));
        int radius = std::stoi(line_split.at(3));
        MiniCAD::Color outline_color = ParseColor(line_split.at(4), line_split.at(5));
        MiniCAD::Color fill_color = ParseColor(line_split.at(6), line_split.at(7));
        circle = new MiniCAD::Circle(center, radius, outline_color, fill_color);
    }
    catch (const std::invalid_argument &)
    {
        circle = nullptr;
    }
    catch (const std::out_of_range &)
    {
        circle = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        circle = nullptr;
    }

    return std::unique_ptr<MiniCAD::Circle>(circle);
}

static std::unique_ptr<MiniCAD::Triangle> CreateTriangle(const std::vector<std::string> &line_split)
{
    MiniCAD::Triangle *triangle = nullptr;

    try
    {
        MiniCAD::Point p0 = ParsePoint(line_split.at(1), line_split.at(2));
        MiniCAD::Point p1 = ParsePoint(line_split.at(3), line_split.at(4));
        MiniCAD::Point p2 = ParsePoint(line_split.at(5), line_split.at(6));
        MiniCAD::Color outline_color = ParseColor(line_split.at(7), line_split.at(8));
        MiniCAD::Color fill_color = ParseColor(line_split.at(9), line_split.at(10));
        triangle = new MiniCAD::Triangle(p0, p1, p2, outline_color, fill_color);
    }
    catch (const std::invalid_argument &)
    {
        triangle = nullptr;
    }
    catch (const std::out_of_range &)
    {
        triangle = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        triangle = nullptr;
    }

    return std::unique_ptr<MiniCAD::Triangle>(triangle);
}

static std::unique_ptr<MiniCAD::Diamond> CreateDiamond(const std::vector<std::string> &line_split)
{
    MiniCAD::Diamond *diamond = nullptr;

    try
    {
        MiniCAD::Point center = ParsePoint(line_split.at(1), line_split.at(2));
        int horizontal_diagonal = std::stoi(line_split.at(3));
        int vertical_diagonal = std::stoi(line_split.at(4));
        MiniCAD::Color outline_color = ParseColor(line_split.at(5), line_split.at(6));
        MiniCAD::Color fill_color = ParseColor(line_split.at(7), line_split.at(8));
        diamond = new MiniCAD::Diamond(center, horizontal_diagonal, vertical_diagonal,
                                       outline_color, fill_color);
    }
    catch (const std::invalid_argument &)
    {
        diamond = nullptr;
    }
    catch (const std::out_of_range &)
    {
        diamond = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        diamond = nullptr;
    }

    return std::unique_ptr<MiniCAD::Diamond>(diamond);
}

static std::unique_ptr<MiniCAD::Polygon> CreatePolygon(const std::vector<std::string> &line_split)
{
    MiniCAD::Polygon *polygon = nullptr;

    try
    {
        std::vector<MiniCAD::Point> points;
        int points_num = std::stoi(line_split.at(1));

        points.reserve(points_num);
        for (std::size_t coordinate_index = 2; coordinate_index < line_split.size() - 4; coordinate_index += 2)
        {
            MiniCAD::Point p = ParsePoint(line_split.at(coordinate_index), line_split.at(coordinate_index + 1));
            points.push_back(p);
        }

        int color_index = line_split.size() - 4;
        MiniCAD::Color outline_color = ParseColor(line_split.at(color_index), line_split.at(color_index + 1));
        MiniCAD::Color fill_color = ParseColor(line_split.at(color_index + 2), line_split.at(color_index + 3));

        polygon = new MiniCAD::Polygon(points, outline_color, fill_color);
    }
    catch (const std::invalid_argument &)
    {
        polygon = nullptr;
    }
    catch (const std::out_of_range &)
    {
        polygon = nullptr;
    }
    catch (const std::bad_alloc &)
    {
        polygon = nullptr;
    }

    return std::unique_ptr<MiniCAD::Polygon>(polygon);
}

static std::vector<std::string> SplitString(const std::string &string, char delimiter)
{
    std::stringstream string_stream(string);
    std::vector<std::string> parts;
    std::string part;

    while ( !(std::getline(string_stream, part, delimiter).fail()) )
    {
        parts.push_back(part);
    }
    return parts;
}

namespace MiniCAD
{
    std::unique_ptr<Shape> ShapeFactory::CreateShape(const std::string &line) const
    {
        std::vector<std::string> line_splits = SplitString(line, LineProperties::Delimitator);
        std::unique_ptr<Shape> shape = nullptr;

        if (line_splits.empty())
        {
            shape = nullptr;
        }
        else if (*line_splits.begin() == ShapeNames::Canvas)
        {
            shape = CreateCanvas(line_splits);
        }
        else if (*line_splits.begin() == ShapeNames::Line)
        {
            shape = CreateLine(line_splits);
        }
        else if (*line_splits.begin() == ShapeNames::Square)
        {
            shape = CreateSquare(line_splits);
        }
        else if (*line_splits.begin() == ShapeNames::Rectangle)
        {
            shape = CreateRectangle(line_splits);
        }
        else if (*line_splits.begin() == ShapeNames::Circle)
        {
            shape = CreateCircle(line_splits);
        }
        else if (*line_splits.begin() == ShapeNames::Triangle)
        {
            shape = CreateTriangle(line_splits);
        }
        else if (*line_splits.begin() == ShapeNames::Diamond)
        {
            shape = CreateDiamond(line_splits);
        }
        else if (*line_splits.begin() == ShapeNames::Polygon)
        {
            shape = CreatePolygon(line_splits);
        }

        return shape;
    }
}
