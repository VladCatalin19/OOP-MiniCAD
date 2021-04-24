#pragma once

#include "Shape.h"
#include "../Utils/Point.h"
#include "../Utils/Color.h"
#include <ostream>

class Diamond: public Shape
{
private:
	Point center;
	int horizontalDiagonal, verticalDiagonal;
	Color outlineColor, fillColor;

public:
	Diamond(Point center, int horizontalDiagonal, int verticalDiagonal,
		Color outlineColor, Color fillColor);
	virtual ~Diamond();

	Point GetCenterPoint() const;
	int GetHorizontalDiagonal() const;
	int GetVerticalDiagonal() const;
	Color GetOutlineColor() const;
	Color GetFillColor() const;

	void Accept(ShapeVisitor& visitor) const override;

	friend std::ostream& operator<<(std::ostream& os, Diamond const& diamond);
};
