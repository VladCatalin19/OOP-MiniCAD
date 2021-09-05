#ifndef MINICAD_SOURCE_SHAPES_RECTANGLE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_RECTANGLE_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    class Rectangle: public Shape
    {
    private:
        Point top_left;
        unsigned height, width;
        Color outline_color, fill_color;

    public:
        Rectangle(Point top_left, unsigned height, unsigned width, Color outline_color,
                  Color fill_color);
        ~Rectangle();

        Point GetTopLeftPoint() const;
        unsigned GetHeight() const;
        unsigned GetWidth() const;
        Color GetOutlineColor() const;
        Color GetFillColor() const;

        void Accept(ShapeVisitor &visitor) const override;

        friend std::ostream& operator<<(std::ostream &os, const Rectangle &rectangle);
    };
}

#endif // MINICAD_SOURCE_SHAPES_RECTANGLE_HPP_INCLUDED
