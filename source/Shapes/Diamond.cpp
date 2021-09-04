#include "Diamond.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>
#include <Utils/Point.hpp>

#include <ostream>              // std::ostream
#include <string>               // std::to_string

namespace MiniCAD
{
    Diamond::Diamond(Point center, int horizontal_diagonal, int vertical_diagonal,
                     Color outline_color, Color fill_color)
        : center(center),
          horizontal_diagonal(horizontal_diagonal), vertical_diagonal(vertical_diagonal),
          outline_color(outline_color), fill_color(fill_color)
    {
        
    }

    Diamond::~Diamond()
    {

    }

    Point Diamond::GetCenterPoint() const
    {
        return center;
    }

    int Diamond::GetHorizontalDiagonal() const
    {
        return horizontal_diagonal;
    }

    int Diamond::GetVerticalDiagonal() const
    {
        return vertical_diagonal;
    }

    Color Diamond::GetOutlineColor() const
    {
        return outline_color;
    }

    Color Diamond::GetFillColor() const
    {
        return fill_color;
    }

    void Diamond::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream &os, const Diamond &diamond)
    {
        return os << ShapeNames::Diamond
                  << " " << diamond.center
                  << " " << std::to_string(diamond.horizontal_diagonal)
                  << " " << std::to_string(diamond.vertical_diagonal)
                  << " " << diamond.outline_color
                  << " " << diamond.fill_color;
    }
}
