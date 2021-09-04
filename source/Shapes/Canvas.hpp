#ifndef MINICAD_SOURCE_SHAPES_CANVAS_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_CANVAS_HPP_INCLUDED

#include "Shape.hpp"
#include <Utils/Color.hpp>
#include <ostream>

class Canvas: public Shape
{
private:
	int height, width;
	Color color;

public:
	Canvas(int height, int width, Color color);
	virtual ~Canvas();

	int GetHeight() const;
	int GetWidth() const;
	Color GetColor() const;

	void Accept(ShapeVisitor& visitor) const override;
	friend std::ostream& operator<<(std::ostream& os, Canvas const& canvas);
};

#endif // MINICAD_SOURCE_SHAPES_CANVAS_HPP_INCLUDED
