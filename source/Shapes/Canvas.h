#pragma once

#include "Shape.h"
#include "../Utils/Color.h"
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
