#pragma once

#include <string>

class Shape;

class ShapeFactory
{
private:
	ShapeFactory() {}

public:
	static ShapeFactory& GetInstance()
	{
		static ShapeFactory instance;
		return instance;
	}

	ShapeFactory(ShapeFactory const&) = delete;
	void operator=(ShapeFactory const&) = delete;

	Shape* CreateShape(std::string const& line) const;
};
