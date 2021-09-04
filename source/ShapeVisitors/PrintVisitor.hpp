#ifndef MINICAD_SOURCE_SHAPEVISITORS_PRINTVISITOR_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPEVISITORS_PRINTVISITOR_HPP_INCLUDED

#include "ShapeVisitor.hpp"

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
    class PrintVisitor : public ShapeVisitor
    {
    public:
        PrintVisitor();
        virtual ~PrintVisitor();

        virtual void Visit(const Canvas &canvas) override;
        virtual void Visit(const Line &line) override;
        virtual void Visit(const Square &square) override;
        virtual void Visit(const Rectangle &rectangle) override;
        virtual void Visit(const Circle &circle) override;
        virtual void Visit(const Triangle &triangle) override;
        virtual void Visit(const Diamond &diamond) override;
        virtual void Visit(const Polygon &polygon) override;
    };
}

#endif // MINICAD_SOURCE_SHAPEVISITORS_PRINTVISITOR_HPP_INCLUDED
