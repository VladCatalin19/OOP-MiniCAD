#include "Circle.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Constants.hpp>

Circle::Circle(Point center, int radius, Color outlineColor, Color fillColor)
	: center(center), outlineColor(outlineColor), fillColor(fillColor)
{
	this->radius = radius;
}

Circle::~Circle()
{

}

Point Circle::GetCenterPoint() const
{
	return center;
}

int Circle::GetRadius() const
{
	return radius;
}

Color Circle::GetOutlineColor() const
{
	return outlineColor;
}

Color Circle::GetFillColor() const
{
	return fillColor;
}

void Circle::Accept(ShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

std::ostream& operator<<(std::ostream& os, Circle const& circle)
{
	return os << ShapeNames::Circle
		<< " " << circle.center
		<< " " << std::to_string(circle.radius)
		<< " " << circle.outlineColor
		<< " " << circle.fillColor;
}
