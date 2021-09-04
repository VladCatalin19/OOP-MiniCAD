#ifndef MINICAD_SOURCE_SHAPES_DIAMOND_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_DIAMOND_HPP_INCLUDED

#include "Shape.hpp"
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
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

#endif // MINICAD_SOURCE_SHAPES_DIAMOND_HPP_INCLUDED
