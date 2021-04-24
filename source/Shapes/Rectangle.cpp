#include "Rectangle.h"
#include "../ShapeVisitors/ShapeVisitor.h"
#include "../Utils/Constants.h"

Rectangle::Rectangle(Point topLeft, int height, int width, Color outlineColor,
	Color fillColor)
	: topLeft(topLeft), outlineColor(outlineColor), fillColor(fillColor)
{
	this->height = height;
	this->width = width;
}

Rectangle::~Rectangle()
{

}

Point Rectangle::GetTopLeftPoint() const
{
	return topLeft;
}

int Rectangle::GetHeight() const
{
	return height;
}

int Rectangle::GetWidth() const
{
	return width;
}

Color Rectangle::GetOutlineColor() const
{
	return outlineColor;
}

Color Rectangle::GetFillColor() const
{
	return fillColor;
}

void Rectangle::Accept(ShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

std::ostream& operator<<(std::ostream& os, Rectangle const& rectangle)
{
	return os << ShapeNames::Rectangle
		<< " " << rectangle.topLeft
		<< " " << rectangle.height
		<< " " << rectangle.width
		<< " " << rectangle.outlineColor
		<< " " << rectangle.fillColor;
}
