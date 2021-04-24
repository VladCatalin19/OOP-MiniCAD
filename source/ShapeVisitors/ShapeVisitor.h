#pragma once

class Canvas;
class Line;
class Square;
class Rectangle;
class Circle;
class Triangle;
class Diamond;
class Polygon;

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
