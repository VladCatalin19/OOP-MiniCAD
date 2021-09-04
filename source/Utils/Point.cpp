#include "Point.hpp"

#include <iostream>

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{

}

std::ostream& operator<<(std::ostream& os, Point const& point)
{
    return os << "(" << std::to_string(point.x)
        << ", " + std::to_string(point.y) << ")";
}
