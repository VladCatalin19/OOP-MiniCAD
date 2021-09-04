#ifndef MINICAD_SOURCE_SHAPES_RECTANGLE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_RECTANGLE_HPP_INCLUDED

#include "Shape.hpp"
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
#include <ostream>

class Rectangle: public Shape
{
private:
    Point topLeft;
    int height, width;
    Color outlineColor, fillColor;

public:
    Rectangle(Point topLeft, int height, int width, Color outlineColor,
        Color fillColor);
    ~Rectangle();

    Point GetTopLeftPoint() const;
    int GetHeight() const;
    int GetWidth() const;
    Color GetOutlineColor() const;
    Color GetFillColor() const;

    void Accept(ShapeVisitor& visitor) const override;

    friend std::ostream& operator<<(std::ostream& os, Rectangle const& rectangle);
};

#endif // MINICAD_SOURCE_SHAPES_RECTANGLE_HPP_INCLUDED
