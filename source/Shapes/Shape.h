#pragma once

#include <ostream>

class ShapeVisitor;

class Shape
{
public:
	virtual ~Shape() {}
	virtual void Accept(ShapeVisitor& visitor) const = 0;
};
