#include "Square.h"
#include "../ShapeVisitors/ShapeVisitor.h"
#include "../Utils/Constants.h"

Square::Square(Point topLeft, int side, Color outlineColor, Color fillColor)
	: topLeft(topLeft), outlineColor(outlineColor), fillColor(fillColor)
{
	this->side = side;
}

Square::~Square()
{

}

Point Square::GetTopLeftPoint() const
{
	return topLeft;
}

int Square::GetSide() const
{
	return side;
}

Color Square::GetOutlineColor() const
{
	return outlineColor;
}

Color Square::GetFillColor() const
{
	return fillColor;
}

void Square::Accept(ShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

std::ostream& operator<<(std::ostream& os, Square const& square)
{
	return os << ShapeNames::Square
		<< " " << square.topLeft
		<< " " << square.side
		<< " " << square.outlineColor
		<< " " << square.fillColor;
}
