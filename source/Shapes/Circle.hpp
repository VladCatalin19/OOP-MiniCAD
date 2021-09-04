#ifndef MINICAD_SOURCE_SHAPES_CIRCLE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_CIRCLE_HPP_INCLUDED

#include "Shape.hpp"
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
#include <ostream>

class Circle: public Shape
{
private:
    Point center;
    int radius;
    Color outlineColor, fillColor;

public:
    Circle(Point center, int radius, Color outlineColor, Color fillColor);
    virtual ~Circle();

    Point GetCenterPoint() const;
    int GetRadius() const;
    Color GetOutlineColor() const;
    Color GetFillColor() const;

    void Accept(ShapeVisitor& visitor) const override;

    friend std::ostream& operator<<(std::ostream& os, Circle const& circle);
};

#endif // MINICAD_SOURCE_SHAPES_CIRCLE_HPP_INCLUDED
