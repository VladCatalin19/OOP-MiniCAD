#include "Color.hpp"

#include <ostream>
#include <iomanip>

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color::~Color()
{

}

std::ostream& operator<<(std::ostream& os, Color const& color)
{
    return os << "#" << std::hex << std::setfill('0')
        << std::setw(2) << static_cast<int>(color.r)
        << std::setw(2) << static_cast<int>(color.g)
        << std::setw(2) << static_cast<int>(color.b)
        << " " << std::dec << static_cast<int>(color.a);
}
