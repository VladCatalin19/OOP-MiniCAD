#ifndef MINICAD_SOURCE_SHAPES_POLYGON_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_POLYGON_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Point.hpp>
#include <Utils/Color.hpp>

#include <ostream>              // std::ostream
#include <vector>               // std::vector

namespace MiniCAD
{
    class Polygon: public Shape
    {
    private:
        std::vector<Point> points;
        Color outline_color, fill_color;

    public:
        Polygon(std::vector<Point> points, Color outline_color, Color fill_color);
        virtual ~Polygon();

        std::vector<Point> GetPoints() const;
        Color GetOutlineColor() const;
        Color GetFillColor() const;

        void Accept(ShapeVisitor &visitor) const override;

        friend std::ostream& operator<<(std::ostream &os, const Polygon &polygon);
    };
}

#endif // MINICAD_SOURCE_SHAPES_POLYGON_HPP_INCLUDED
