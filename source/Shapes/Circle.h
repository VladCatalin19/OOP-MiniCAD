#pragma once

#include "Shape.h"
#include "../Utils/Point.h"
#include "../Utils/Color.h"
#include <ostream>

class Circle: public Shape
{
private:
	Point center;
	int radius;
	Color outlineColor, fillColor;

public:
	Circle(Point center, int radius, Color outlineColor, Color fillColor);
	virtual ~Circle();

	Point GetCenterPoint() const;
	int GetRadius() const;
	Color GetOutlineColor() const;
	Color GetFillColor() const;

	void Accept(ShapeVisitor& visitor) const override;

	friend std::ostream& operator<<(std::ostream& os, Circle const& circle);
};
