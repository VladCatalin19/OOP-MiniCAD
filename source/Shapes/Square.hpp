#ifndef MINICAD_SOURCE_SHAPES_SQUARE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_SQUARE_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    class Square: public Shape
    {
    private:
        Point top_left;
        int side;
        Color outline_color, fill_color;

    public:
        Square(Point top_left, int side, Color outline_color, Color fill_color);
        virtual ~Square();

        Point GetTopLeftPoint() const;
        int GetSide() const;
        Color GetOutlineColor() const;
        Color GetFillColor() const;

        void Accept(ShapeVisitor &visitor) const override;

        friend std::ostream& operator<<(std::ostream &os, const Square &square);
    };
}

#endif // MINICAD_SOURCE_SHAPES_SQUARE_HPP_INCLUDED
