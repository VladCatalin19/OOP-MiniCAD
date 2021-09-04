#ifndef MINICAD_SOURCE_SHAPES_SQUARE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_SQUARE_HPP_INCLUDED

#include "Shape.hpp"
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

class Square: public Shape
{
private:
    Point topLeft;
    int side;
    Color outlineColor, fillColor;

public:
    Square(Point topLeft, int side, Color outlineColor, Color fillColor);
    virtual ~Square();

    Point GetTopLeftPoint() const;
    int GetSide() const;
    Color GetOutlineColor() const;
    Color GetFillColor() const;

    void Accept(ShapeVisitor& visitor) const override;

    friend std::ostream& operator<<(std::ostream& os, Square const& square);
};

#endif // MINICAD_SOURCE_SHAPES_SQUARE_HPP_INCLUDED
