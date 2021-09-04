#include "Canvas.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Constants.hpp>

#include <string>

Canvas::Canvas(int _height, int _width, Color _color)
    : height(_height), width(_width), color(_color)
{

}

Canvas::~Canvas()
{

}

int Canvas::GetHeight() const
{
    return height;
}

int Canvas::GetWidth() const
{
    return width;
}

Color Canvas::GetColor() const
{
    return color;
}

void Canvas::Accept(ShapeVisitor& visitor) const
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
