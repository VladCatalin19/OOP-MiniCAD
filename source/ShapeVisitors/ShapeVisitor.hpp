#ifndef MINICAD_SOURCE_SHAPEVISITORS_SHAPEVISITOR_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPEVISITORS_SHAPEVISITOR_HPP_INCLUDED

#include <Shapes/Canvas.hpp>
#include <Shapes/Line.hpp>
#include <Shapes/Square.hpp>
#include <Shapes/Rectangle.hpp>
#include <Shapes/Circle.hpp>
#include <Shapes/Triangle.hpp>
#include <Shapes/Diamond.hpp>
#include <Shapes/Polygon.hpp>

namespace MiniCAD
{
    class ShapeVisitor
    {
    public:
        ShapeVisitor() {}
        virtual ~ShapeVisitor() {}

        virtual void Visit(const Canvas &canvas) = 0;
        virtual void Visit(const Line &line) = 0;
        virtual void Visit(const Square &square) = 0;
        virtual void Visit(const Rectangle &rectangle) = 0;
        virtual void Visit(const Circle &circle) = 0;
        virtual void Visit(const Triangle &triangle) = 0;
        virtual void Visit(const Diamond &diamond) = 0;
        virtual void Visit(const Polygon &polygon) = 0;
    };
}

#endif // MINICAD_SOURCE_SHAPEVISITORS_SHAPEVISITOR_HPP_INCLUDED
