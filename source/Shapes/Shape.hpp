#ifndef MINICAD_SOURCE_SHAPES_SHAPE_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_SHAPE_HPP_INCLUDED

#include <ostream>

class ShapeVisitor;

class Shape
{
public:
    virtual ~Shape() {}
    virtual void Accept(ShapeVisitor& visitor) const = 0;
};

#endif // MINICAD_SOURCE_SHAPES_SHAPE_HPP_INCLUDED
