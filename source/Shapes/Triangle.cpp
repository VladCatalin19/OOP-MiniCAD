#include "Triangle.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    Triangle::Triangle(Point p0, Point p1, Point p2, Color outline_color, Color fill_color)
        : p0(p0), p1(p1), p2(p2), outline_color(outline_color), fill_color(fill_color)
    {

    }

    Triangle::~Triangle()
    {

    }

    Point Triangle::GetP0() const
    {
        return p0;
    }

    Point Triangle::GetP1() const
    {
        return p1;
    }

    Point Triangle::GetP2() const
    {
        return p2;
    }

    Color Triangle::GetOutlineColor() const
    {
        return outline_color;
    }

    Color Triangle::GetFillColor() const
    {
        return fill_color;
    }

    void Triangle::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream &os, const Triangle &triangle)
    {
        return os << ShapeNames::Triangle
                  << " " << triangle.p0
                  << " " << triangle.p1
                  << " " << triangle.p2
                  << " " << triangle.outline_color
                  << " " << triangle.fill_color;
    }
}
