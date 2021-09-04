#ifndef MINICAD_SOURCE_SHAPES_LINE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_LINE_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    class Line: public Shape
    {
    private:
        Point p0, p1;
        Color color;

    public:
        Line(Point p0, Point p1, Color color);
        virtual ~Line();

        Point GetP0() const;
        Point GetP1() const;
        Color GetColor() const;

        void Accept(ShapeVisitor &visitor) const override;

        friend std::ostream& operator<<(std::ostream &os , const Line &line);
    };
}

#endif // MINICAD_SOURCE_SHAPES_LINE_HPP_INCLUDED
