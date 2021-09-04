#include "PrintVisitor.hpp"

#include <Shapes/Canvas.hpp>
#include <Shapes/Line.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Rectangle.hpp>
#include <Shapes/Circle.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Diamond.hpp>
#include <Shapes/Polygon.hpp>

#include <iostream>

PrintVisitor::PrintVisitor()
{

}

PrintVisitor::~PrintVisitor()
{

}

void PrintVisitor::Visit(Canvas const& canvas)
{
    std::cout << canvas << "\n";
}

void PrintVisitor::Visit(Line const& line)
{
    std::cout << line << "\n";
}

void PrintVisitor::Visit(Square const& square)
{
    std::cout << square << "\n";
}

void PrintVisitor::Visit(Rectangle const& rectangle)
{
    std::cout << rectangle << "\n";
}

void PrintVisitor::Visit(Circle const& circle)
{
    std::cout << circle << "\n";
}

void PrintVisitor::Visit(Triangle const& triangle)
{
    std::cout << triangle << "\n";
}

void PrintVisitor::Visit(Diamond const& diamond)
{
    std::cout << diamond << "\n";
}

void PrintVisitor::Visit(Polygon const& polygon)
{
    std::cout << polygon << "\n";
}
