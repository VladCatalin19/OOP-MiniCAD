#pragma once

#include <iostream>
#include <string>

struct Point
{
	int x, y;
	Point(int x, int y);
	~Point();

	friend std::ostream& operator<<(std::ostream& os, Point const& point);
};
