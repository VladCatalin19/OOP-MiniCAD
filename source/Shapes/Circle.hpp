#ifndef MINICAD_SOURCE_SHAPES_CIRCLE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_CIRCLE_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    class Circle: public Shape
    {
    private:
        Point center;
        unsigned radius;
        Color outline_color, fill_color;

    public:
        Circle(Point center, unsigned radius, Color outline_color, Color fill_color);
        virtual ~Circle();

        Point GetCenterPoint() const;
        unsigned GetRadius() const;
        Color GetOutlineColor() const;
        Color GetFillColor() const;

        void Accept(ShapeVisitor &visitor) const override;

        friend std::ostream& operator<<(std::ostream &os, const Circle &circle);
    };
}

#endif // MINICAD_SOURCE_SHAPES_CIRCLE_HPP_INCLUDED
