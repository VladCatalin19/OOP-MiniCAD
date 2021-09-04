#include "Point.hpp"

#include <ostream>              // std::ostream
#include <string>               // std::to_string

namespace MiniCAD
{
    Point::Point(int x, int y)
        : x(x), y(y)
    {

    }

    Point::~Point()
    {

    }

    std::ostream& operator<<(std::ostream &os, const Point &point)
    {
        return os << "(" << std::to_string(point.x)
                  << ", " + std::to_string(point.y) << ")";
    }
}
