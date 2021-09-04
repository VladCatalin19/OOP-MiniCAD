#include "Color.hpp"

#include <cstdint>              // std::uint8_t
#include <iomanip>              // std::hex, std::setfill, std::setw, std::dec
#include <ostream>              // std::ostream

namespace MiniCAD
{
    Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : r(r), g(g), b(b), a(a)
    {

    }

    Color::~Color()
    {

    }

    std::ostream& operator<<(std::ostream &os, const Color &color)
    {
        return os << "#" << std::hex << std::setfill('0')
                  << std::setw(2) << static_cast<int>(color.r)
                  << std::setw(2) << static_cast<int>(color.g)
                  << std::setw(2) << static_cast<int>(color.b)
                  << " " << std::dec << static_cast<int>(color.a);
    }
}
