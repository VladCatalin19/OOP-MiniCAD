#include "Circle.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>

#include <ostream>              // std::ostream
#include <string>               // std::to_string

namespace MiniCAD
{
    Circle::Circle(Point center, unsigned radius, Color outline_color, Color fill_color)
        : center(center), radius(radius), outline_color(outline_color), fill_color(fill_color)
    {
        
    }

    Circle::~Circle()
    {

    }

    Point Circle::GetCenterPoint() const
    {
        return center;
    }

    unsigned Circle::GetRadius() const
    {
        return radius;
    }

    Color Circle::GetOutlineColor() const
    {
        return outline_color;
    }

    Color Circle::GetFillColor() const
    {
        return fill_color;
    }

    void Circle::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream& os, Circle const& circle)
    {
        return os << ShapeNames::Circle
                  << " " << circle.center
                  << " " << std::to_string(circle.radius)
                  << " " << circle.outline_color
                  << " " << circle.fill_color;
    }
}
