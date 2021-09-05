#include "Rectangle.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    Rectangle::Rectangle(Point top_left, unsigned height, unsigned width, Color outline_color,
                         Color fill_color)
        : top_left(top_left), height(height), width(width),
          outline_color(outline_color), fill_color(fill_color)
    {
        
    }

    Rectangle::~Rectangle()
    {

    }

    Point Rectangle::GetTopLeftPoint() const
    {
        return top_left;
    }

    unsigned Rectangle::GetHeight() const
    {
        return height;
    }

    unsigned Rectangle::GetWidth() const
    {
        return width;
    }

    Color Rectangle::GetOutlineColor() const
    {
        return outline_color;
    }

    Color Rectangle::GetFillColor() const
    {
        return fill_color;
    }

    void Rectangle::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream &os, const Rectangle &rectangle)
    {
        return os << ShapeNames::Rectangle
                  << " " << rectangle.top_left
                  << " " << rectangle.height
                  << " " << rectangle.width
                  << " " << rectangle.outline_color
                  << " " << rectangle.fill_color;
    }
}
