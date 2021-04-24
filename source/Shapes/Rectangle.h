#pragma once

#include "Shape.h"
#include "../Utils/Point.h"
#include "../Utils/Color.h"
#include <ostream>

class Rectangle: public Shape
{
private:
	Point topLeft;
	int height, width;
	Color outlineColor, fillColor;

public:
	Rectangle(Point topLeft, int height, int width, Color outlineColor,
		Color fillColor);
	~Rectangle();

	Point GetTopLeftPoint() const;
	int GetHeight() const;
	int GetWidth() const;
	Color GetOutlineColor() const;
	Color GetFillColor() const;

	void Accept(ShapeVisitor& visitor) const override;

	friend std::ostream& operator<<(std::ostream& os, Rectangle const& rectangle);
};
