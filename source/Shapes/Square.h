#pragma once

#include "Shape.h"
#include "../Utils/Point.h"
#include "../Utils/Color.h"

class Square: public Shape
{
private:
	Point topLeft;
	int side;
	Color outlineColor, fillColor;

public:
	Square(Point topLeft, int side, Color outlineColor, Color fillColor);
	virtual ~Square();

	Point GetTopLeftPoint() const;
	int GetSide() const;
	Color GetOutlineColor() const;
	Color GetFillColor() const;

	void Accept(ShapeVisitor& visitor) const override;

	friend std::ostream& operator<<(std::ostream& os, Square const& square);
};
