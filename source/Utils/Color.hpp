#ifndef MINICAD_SOURCE_UTILS_COLOR_HPP_INCLUDED
#define MINICAD_SOURCE_UTILS_COLOR_HPP_INCLUDED

#include <cstdint>              // std::uint8_t
#include <ostream>              // std::ostream

namespace MiniCAD
{
    struct Color
    {
        std::uint8_t r, g, b, a;

        Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a);
        ~Color();

        friend std::ostream& operator<<(std::ostream &os, const Color &color);
    };
}

#endif // MINICAD_SOURCE_UTILS_COLOR_HPP_INCLUDED
