#ifndef MINICAD_SOURCE_UTILS_POINT_HPP_INCLUDED
#define MINICAD_SOURCE_UTILS_POINT_HPP_INCLUDED

#include <ostream>              // std::ostream

namespace MiniCAD
{
    struct Point
    {
        int x, y;

        Point(int x, int y);
        ~Point();

        friend std::ostream& operator<<(std::ostream &os, const Point &point);
    };
}

#endif // MINICAD_SOURCE_UTILS_POINT_HPP_INCLUDED
