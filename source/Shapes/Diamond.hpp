#ifndef MINICAD_SOURCE_SHAPES_DIAMOND_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_DIAMOND_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    class Diamond: public Shape
    {
    private:
        Point center;
        int horizontal_diagonal, vertical_diagonal;
        Color outline_color, fill_color;

    public:
        Diamond(Point center, int horizontal_diagonal, int vertical_diagonal,
                Color outline_color, Color fill_color);
        virtual ~Diamond();

        Point GetCenterPoint() const;
        int GetHorizontalDiagonal() const;
        int GetVerticalDiagonal() const;
        Color GetOutlineColor() const;
        Color GetFillColor() const;

        void Accept(ShapeVisitor &visitor) const override;

        friend std::ostream& operator<<(std::ostream &os, const Diamond &diamond);
    };
}

#endif // MINICAD_SOURCE_SHAPES_DIAMOND_HPP_INCLUDED
