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

class ShapeVisitor
{
public:
	ShapeVisitor() {}
	virtual ~ShapeVisitor() {}

	virtual void Visit(Canvas const& canvas) = 0;
	virtual void Visit(Line const& line) = 0;
	virtual void Visit(Square const& square) = 0;
	virtual void Visit(Rectangle const& rectangle) = 0;
	virtual void Visit(Circle const& circle) = 0;
	virtual void Visit(Triangle const& triangle) = 0;
	virtual void Visit(Diamond const& diamond) = 0;
	virtual void Visit(Polygon const& polygon) = 0;
};

#endif // MINICAD_SOURCE_SHAPEVISITORS_SHAPEVISITOR_HPP_INCLUDED
