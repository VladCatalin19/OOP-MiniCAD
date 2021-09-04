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

#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stdexcept>

static Color ParseColor(std::string const& rgb, std::string const& alpha)
{
    unsigned long n = std::stoul(rgb.substr(1, rgb.size() - 1), nullptr, 16);

    unsigned char r = (n & 0xFF0000) >> 16;
    unsigned char g = (n & 0x00FF00) >> 8;
    unsigned char b = n & 0x0000FF;
    unsigned char a = std::stoi(alpha);
    return Color(r, g, b, a);
}

static Canvas* CreateCanvas(std::vector<std::string> const& lineSplit)
{
    Canvas* canvas = nullptr;

    try
    {
        int height = std::stoi(lineSplit[1]);
        int width = std::stoi(lineSplit[2]);
        Color color = ParseColor(lineSplit[3], lineSplit[4]);
        canvas = new Canvas(height, width, color);
    }
    catch (...)
    {
        return nullptr;
    }

    return canvas;
}

static Line* CreateLine(std::vector<std::string> const& lineSplit)
{
    Line* line = nullptr;

    try
    {
        Point p0 = Point(std::stoi(lineSplit[1]), std::stoi(lineSplit[2]));
        Point p1 = Point(std::stoi(lineSplit[3]), std::stoi(lineSplit[4]));
        Color color = ParseColor(lineSplit[5], lineSplit[6]);
        line = new Line(p0, p1, color);
    }
    catch (...)
    {
        return nullptr;
    }

    return line;
}

static Square* CreateSquare(std::vector<std::string> const& lineSplit)
{
    Square* square = nullptr;

    try
    {
        Point topLeft = Point(std::stoi(lineSplit[1]), std::stoi(lineSplit[2]));
        int side = std::stoi(lineSplit[3]);
        Color outlineColor = ParseColor(lineSplit[4], lineSplit[5]);
        Color fillColor = ParseColor(lineSplit[6], lineSplit[7]);
        square = new Square(topLeft, side, outlineColor, fillColor);
    }
    catch (...)
    {
        return nullptr;
    }

    return square;
}

static Rectangle* CreateRectangle(std::vector<std::string> const& lineSplit)
{
    Rectangle* rectangle = nullptr;

    try
    {
        Point topLeft = Point(std::stoi(lineSplit[1]), std::stoi(lineSplit[2]));
        int height = std::stoi(lineSplit[3]);
        int width = std::stoi(lineSplit[4]);
        Color outlineColor = ParseColor(lineSplit[5], lineSplit[6]);
        Color fillColor = ParseColor(lineSplit[7], lineSplit[8]);
        rectangle = new Rectangle(topLeft, height, width, outlineColor, fillColor);
    }
    catch (...)
    {
        return nullptr;
    }

    return rectangle;
}

static Circle* CreateCircle(std::vector<std::string> const& lineSplit)
{
    Circle* circle = nullptr;

    try
    {
        Point center = Point(std::stoi(lineSplit[1]), std::stoi(lineSplit[2]));
        int radius = std::stoi(lineSplit[3]);
        Color outlineColor = ParseColor(lineSplit[4], lineSplit[5]);
        Color fillColor = ParseColor(lineSplit[6], lineSplit[7]);
        circle = new Circle(center, radius, outlineColor, fillColor);
    }
    catch (...)
    {
        return nullptr;
    }

    return circle;
}

static Triangle* CreateTriangle(std::vector<std::string> const& lineSplit)
{
    Triangle* triangle = nullptr;

    try
    {
        Point p0 = Point(std::stoi(lineSplit[1]), std::stoi(lineSplit[2]));
        Point p1 = Point(std::stoi(lineSplit[3]), std::stoi(lineSplit[4]));
        Point p2 = Point(std::stoi(lineSplit[5]), std::stoi(lineSplit[6]));
        Color outlineColor = ParseColor(lineSplit[7], lineSplit[8]);
        Color fillColor = ParseColor(lineSplit[9], lineSplit[10]);
        triangle = new Triangle(p0, p1, p2, outlineColor, fillColor);
    }
    catch (...)
    {
        return nullptr;
    }

    return triangle;
}

static Diamond* CreateDiamond(std::vector<std::string> const& lineSplit)
{
    Diamond* diamond = nullptr;

    try
    {
        Point center = Point(std::stoi(lineSplit[1]), std::stoi(lineSplit[2]));
        int horizDiag = std::stoi(lineSplit[3]);
        int vertDiag = std::stoi(lineSplit[4]);
        Color outlineColor = ParseColor(lineSplit[5], lineSplit[6]);
        Color fillColor = ParseColor(lineSplit[7], lineSplit[8]);
        diamond = new Diamond(center, horizDiag, vertDiag, outlineColor, fillColor);
    }
    catch (...)
    {
        return nullptr;
    }

    return diamond;
}

static Polygon* CreatePolygon(std::vector<std::string> const& lineSplit)
{
    Polygon* polygon = nullptr;

    try
    {
        std::vector<Point> points = std::vector<Point>();
        int pointsNum = std::stoi(lineSplit[1]);

        points.reserve(pointsNum);
        for (int i = 2; i < static_cast<int>(lineSplit.size()) - 4; i += 2)
        {
            Point p = Point(std::stoi(lineSplit[i]), std::stoi(lineSplit[i + 1]));
            points.push_back(p);
        }

        int colIdx = lineSplit.size() - 4;
        Color outlineColor = ParseColor(lineSplit[colIdx], lineSplit[colIdx + 1]);
        Color fillColor = ParseColor(lineSplit[colIdx + 2], lineSplit[colIdx + 3]);

        polygon = new Polygon(points, outlineColor, fillColor);
    }
    catch (...)
    {
        return nullptr;
    }

    return polygon;
}

static std::vector<std::string> SplitString(std::string const& str, char delim)
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

Shape* ShapeFactory::CreateShape(std::string const& line) const
{
    Shape* shape = nullptr;
    std::vector<std::string> lineSplits = SplitString(line, LineProperties::Delimitator);

    if (lineSplits.size() == 0)
    {
        return nullptr;
    }

    if (lineSplits[0].compare(ShapeNames::Canvas) == 0)
    {
        shape = CreateCanvas(lineSplits);
    }
    else if (lineSplits[0].compare(ShapeNames::Line) == 0)
    {
        shape = CreateLine(lineSplits);
    }
    else if (lineSplits[0].compare(ShapeNames::Square) == 0)
    {
        shape = CreateSquare(lineSplits);
    }
    else if (lineSplits[0].compare(ShapeNames::Rectangle) == 0)
    {
        shape = CreateRectangle(lineSplits);
    }
    else if (lineSplits[0].compare(ShapeNames::Circle) == 0)
    {
        shape = CreateCircle(lineSplits);
    }
    else if (lineSplits[0].compare(ShapeNames::Triangle) == 0)
    {
        shape = CreateTriangle(lineSplits);
    }
    else if (lineSplits[0].compare(ShapeNames::Diamond) == 0)
    {
        shape = CreateDiamond(lineSplits);
    }
    else if (lineSplits[0].compare(ShapeNames::Polygon) == 0)
    {
        shape = CreatePolygon(lineSplits);
    }

    return shape;
}
