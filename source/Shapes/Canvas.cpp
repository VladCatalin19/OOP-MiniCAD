#include "Canvas.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Color.hpp>
#include <Utils/Constants.hpp>

#include <ostream>              // std::ostream
#include <string>               // std::string, std::to_string

namespace MiniCAD
{
    Canvas::Canvas(unsigned height, unsigned width, Color color)
        : height(height), width(width), color(color)
    {

    }

    Canvas::~Canvas()
    {

    }

    unsigned Canvas::GetHeight() const
    {
        return height;
    }

    unsigned Canvas::GetWidth() const
    {
        return width;
    }

    Color Canvas::GetColor() const
    {
        return color;
    }

    void Canvas::Accept(ShapeVisitor &visitor) const
    {
        visitor.Visit(*this);
    }

    std::ostream& operator<<(std::ostream& os, Canvas const& canvas)
    {
        return os << ShapeNames::Canvas
                  << " " << std::to_string(canvas.height)
                  << " " << std::to_string(canvas.width)
                  << " " << canvas.color;
    }
}
