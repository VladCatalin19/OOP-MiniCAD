#include "Polygon.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Point.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>

#include <ostream>              // std::ostream
#include <vector>               // std::vector

namespace MiniCAD
{
    Polygon::Polygon(std::vector<Point> points, Color outline_color, Color fill_color)
        : points(points), outline_color(outline_color), fill_color(fill_color)
    {
        
    }

    Polygon::~Polygon()
    {

    }

    std::vector<Point> Polygon::GetPoints() const
    {
        return points;
    }

    Color Polygon::GetOutlineColor() const
    {
        return outline_color;
    }

    Color Polygon::GetFillColor() const
    {
        return fill_color;
    }

    void Polygon::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream &os, const Polygon &polygon)
    {
        os << ShapeNames::Polygon;

        for (Point const& p : polygon.points)
        {
            os << " " << p;
        }

        return os << " " << polygon.outline_color << " " << polygon.fill_color;
    }
}
