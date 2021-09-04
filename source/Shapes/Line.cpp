#include "Line.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    Line::Line(Point p0, Point p1, Color color)
        : p0(p0), p1(p1), color(color)
    {

    }

    Line::~Line()
    {

    }

    Point Line::GetP0() const
    {
        return p0;
    }

    Point Line::GetP1() const
    {
        return p1;
    }

    Color Line::GetColor() const
    {
        return color;
    }

    void Line::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream &os, const Line &line)
    {
        return os << ShapeNames::Line
                  << " " << line.p0
                  << " " << line.p1
                  << " " << line.color;
    }
}
