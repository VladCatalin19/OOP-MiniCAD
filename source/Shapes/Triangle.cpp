#include "Triangle.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Constants.hpp>

Triangle::Triangle(Point p0, Point p1, Point p2, Color outlineColor, Color fillColor)
	: p0(p0), p1(p1), p2(p2), outlineColor(outlineColor), fillColor(fillColor)
{

}

Triangle::~Triangle()
{

}

Point Triangle::GetP0() const
{
	return p0;
}

Point Triangle::GetP1() const
{
	return p1;
}

Point Triangle::GetP2() const
{
	return p2;
}

Color Triangle::GetOutlineColor() const
{
	return outlineColor;
}

Color Triangle::GetFillColor() const
{
	return fillColor;
}

void Triangle::Accept(ShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

std::ostream& operator<<(std::ostream& os, Triangle const& triangle)
{
	return os << ShapeNames::Triangle
		<< " " << triangle.p0
		<< " " << triangle.p1
		<< " " << triangle.p2
		<< " " << triangle.outlineColor
		<< " " << triangle.fillColor;
}
