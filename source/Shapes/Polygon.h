#pragma once

#include "Shape.h"
#include "../Utils/Point.h"
#include "../Utils/Color.h"

#include <ostream>
#include <vector>

class Polygon: public Shape
{
private:
	std::vector<Point> points;
	Color outlineColor, fillColor;

public:
	Polygon(std::vector<Point> points, Color outlineColor, Color fillColor);
	virtual ~Polygon();

	std::vector<Point> GetPoints() const;
	Color GetOutlineColor() const;
	Color GetFillColor() const;

	void Accept(ShapeVisitor& visitor) const override;

	friend std::ostream& operator<<(std::ostream& os, Polygon const& polygon);
};
