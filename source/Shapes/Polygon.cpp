#include "Polygon.h"
#include "../ShapeVisitors/ShapeVisitor.h"
#include "../Utils/Constants.h"

Polygon::Polygon(std::vector<Point> points, Color outlineColor, Color fillColor)
	: outlineColor(outlineColor), fillColor(fillColor)
{
	this->points = points;
}

Polygon::~Polygon()
{

}

std::vector<Point> Polygon::GetPoints() const
{
	return points;
}

Color Polygon::GetOutlineColor() const
{
	return outlineColor;
}

Color Polygon::GetFillColor() const
{
	return fillColor;
}

void Polygon::Accept(ShapeVisitor& visitor) const
{
	visitor.Visit(*this);
}

std::ostream& operator<<(std::ostream& os, Polygon const& polygon)
{
	os << ShapeNames::Polygon;

	for (Point const& p : polygon.points)
	{
		os << " " << p;
	}

	return os << " " << polygon.outlineColor << " " << polygon.fillColor;
}
