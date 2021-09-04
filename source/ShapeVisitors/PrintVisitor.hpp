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

class PrintVisitor : public ShapeVisitor
{
public:
    PrintVisitor();
    ~PrintVisitor();

	virtual void Visit(Canvas const& canvas) override;
	virtual void Visit(Line const& line) override;
	virtual void Visit(Square const& square) override;
	virtual void Visit(Rectangle const& rectangle) override;
	virtual void Visit(Circle const& circle) override;
	virtual void Visit(Triangle const& triangle) override;
	virtual void Visit(Diamond const& diamond) override;
	virtual void Visit(Polygon const& polygon) override;
};

#endif // MINICAD_SOURCE_SHAPEVISITORS_PRINTVISITOR_HPP_INCLUDED
