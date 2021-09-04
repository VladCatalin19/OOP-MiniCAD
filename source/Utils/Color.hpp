#ifndef MINICAD_SOURCE_UTILS_COLOR_HPP_INCLUDED
#define MINICAD_SOURCE_UTILS_COLOR_HPP_INCLUDED

#include <iostream>
#include <cstdint>
#include <string>

struct Color
{
	uint8_t r, g, b, a;
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
	~Color();

	friend std::ostream& operator<<(std::ostream& os, Color const& color);
};

#endif // MINICAD_SOURCE_UTILS_COLOR_HPP_INCLUDED
