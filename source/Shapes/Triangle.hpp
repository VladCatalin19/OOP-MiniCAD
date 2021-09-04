#ifndef MINICAD_SOURCE_SHAPES_TRIANGLE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_TRIANGLE_HPP_INCLUDED

#include "Shape.hpp"
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

class Triangle : public Shape
{
private:
    Point p0, p1, p2;
    Color outlineColor, fillColor;

public:
    Triangle(Point p0, Point p1, Point p2, Color outlineColor, Color fillColor);
    virtual ~Triangle();

    Point GetP0() const;
    Point GetP1() const;
    Point GetP2() const;
    Color GetOutlineColor() const;
    Color GetFillColor() const;

    void Accept(ShapeVisitor& visitor) const override;

    friend std::ostream& operator<<(std::ostream& os, Triangle const& triangle);
};

#endif // MINICAD_SOURCE_SHAPES_TRIANGLE_HPP_INCLUDED
