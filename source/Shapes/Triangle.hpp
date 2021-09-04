#ifndef MINICAD_SOURCE_SHAPES_TRIANGLE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_TRIANGLE_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    class Triangle : public Shape
    {
    private:
        Point p0, p1, p2;
        Color outline_color, fill_color;

    public:
        Triangle(Point p0, Point p1, Point p2, Color outline_color, Color fill_color);
        virtual ~Triangle();

        Point GetP0() const;
        Point GetP1() const;
        Point GetP2() const;
        Color GetOutlineColor() const;
        Color GetFillColor() const;

        void Accept(ShapeVisitor &visitor) const override;

        friend std::ostream& operator<<(std::ostream &os, const Triangle &triangle);
    };
}

#endif // MINICAD_SOURCE_SHAPES_TRIANGLE_HPP_INCLUDED
