#ifndef MINICAD_SOURCE_UTILS_CONSTANTS_HPP_INCLUDED
#define MINICAD_SOURCE_UTILS_CONSTANTS_HPP_INCLUDED

namespace MiniCAD::LineProperties
{
    constexpr inline char Delimitator = ' ';
}

namespace MiniCAD::ShapeNames
{
    constexpr inline char Canvas[] = "CANVAS";
    constexpr inline char Line[] = "LINE";
    constexpr inline char Square[] = "SQUARE";
    constexpr inline char Rectangle[] = "RECTANGLE";
    constexpr inline char Circle[] = "CIRCLE";
    constexpr inline char Triangle[] = "TRIANGLE";
    constexpr inline char Diamond[] = "DIAMOND";
    constexpr inline char Polygon[] = "POLYGON";
}

namespace MiniCAD::Errors
{
    constexpr inline int NotEnoughArguments = 1;
}

namespace MiniCAD::ErrorMessages
{
    constexpr inline char CouldNotOpenFile[] = "Could not open file";
    constexpr inline char CouldNotReadShapesNum[] = "Could not read number of shapes";
    constexpr inline char InvalidShape[] = "Invalid shape";
    constexpr inline char InvalidFillStartingPoint[] = "Invalid starting point for flood fill";
}

#endif // MINICAD_SOURCE_UTILS_CONSTANTS_HPP_INCLUDED
