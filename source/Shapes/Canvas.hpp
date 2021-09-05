#ifndef MINICAD_SOURCE_SHAPES_CANVAS_HPP_INCLUDED
#define MINICAD_SOURCE_SHAPES_CANVAS_HPP_INCLUDED

#include "Shape.hpp"

#include <Utils/Color.hpp>

#include <ostream>              // std::ostream

namespace MiniCAD
{
    class Canvas: public Shape
    {
    private:
        unsigned height, width;
        Color color;

    public:
        Canvas(unsigned height, unsigned width, Color color);
        virtual ~Canvas();

        unsigned GetHeight() const;
        unsigned GetWidth() const;
        Color GetColor() const;

        void Accept(ShapeVisitor &visitor) const override;
        friend std::ostream& operator<<(std::ostream &os, const Canvas &canvas);
    };
}

#endif // MINICAD_SOURCE_SHAPES_CANVAS_HPP_INCLUDED
