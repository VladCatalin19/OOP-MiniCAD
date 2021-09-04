#pragma once

#include <string>

namespace LineProperties
{
    const char Delimitator = ' ';
}

namespace ShapeNames
{
    const std::string Canvas = "CANVAS";
    const std::string Line = "LINE";
    const std::string Square = "SQUARE";
    const std::string Rectangle = "RECTANGLE";
    const std::string Circle = "CIRCLE";
    const std::string Triangle = "TRIANGLE";
    const std::string Diamond = "DIAMOND";
    const std::string Polygon = "POLYGON";
}

namespace Errors
{
    const int NotEnoughArguments = 1;
}

namespace ErrorMessages
{
    const std::string CouldNotOpenFile = "Could not open file";
    const std::string CouldNotReadShapesNum = "Could not read number of shapes";
    const std::string InvalidShape = "Invalid shape";
    const std::string InvalidFillStartingPoint = "Invalid starting point for flood fill";
}
