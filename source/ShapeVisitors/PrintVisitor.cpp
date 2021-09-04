#include "PrintVisitor.hpp"

#include <Shapes/Canvas.hpp>
#include <Shapes/Line.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Rectangle.hpp>
#include <Shapes/Circle.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Diamond.hpp>
#include <Shapes/Polygon.hpp>

#include <iostream>             // std::cout

namespace MiniCAD
{
    PrintVisitor::PrintVisitor()
    {

    }

    PrintVisitor::~PrintVisitor()
    {

    }

    void PrintVisitor::Visit(const Canvas &canvas)
    {
        std::cout << canvas << "\n";
    }

    void PrintVisitor::Visit(const Line &line)
    {
        std::cout << line << "\n";
    }

    void PrintVisitor::Visit(const Square &square)
    {
        std::cout << square << "\n";
    }

    void PrintVisitor::Visit(const Rectangle &rectangle)
    {
        std::cout << rectangle << "\n";
    }

    void PrintVisitor::Visit(const Circle &circle)
    {
        std::cout << circle << "\n";
    }

    void PrintVisitor::Visit(const Triangle &triangle)
    {
        std::cout << triangle << "\n";
    }

    void PrintVisitor::Visit(const Diamond &diamond)
    {
        std::cout << diamond << "\n";
    }

    void PrintVisitor::Visit(const Polygon &polygon)
    {
        std::cout << polygon << "\n";
    }
}
