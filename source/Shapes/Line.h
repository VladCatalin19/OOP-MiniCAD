#pragma once

#include "Shape.h"
#include "../Utils/Point.h"
#include "../Utils/Color.h"
#include <ostream>

class Line: public Shape
{
private:
	Point p0, p1;
	Color color;

public:
	Line(Point p0, Point p1, Color color);
	virtual ~Line();

	Point GetP0() const;
	Point GetP1() const;
	Color GetColor() const;

	void Accept(ShapeVisitor& visitor) const override;

	friend std::ostream& operator<<(std::ostream& os , Line const& line);
};
