#include "Square.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    Square::Square(Point top_left, unsigned side, Color outline_color, Color fill_color)
        : top_left(top_left), side(side), outline_color(outline_color), fill_color(fill_color)
    {
        
    }

    Square::~Square()
    {

    }

    Point Square::GetTopLeftPoint() const
    {
        return top_left;
    }

    unsigned Square::GetSide() const
    {
        return side;
    }

    Color Square::GetOutlineColor() const
    {
        return outline_color;
    }

    Color Square::GetFillColor() const
    {
        return fill_color;
    }

    void Square::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream &os, const Square &square)
    {
        return os << ShapeNames::Square
                  << " " << square.top_left
                  << " " << square.side
                  << " " << square.outline_color
                  << " " << square.fill_color;
    }
}
