#include "Diamond.hpp"

#include <ShapeVisitors/ShapeVisitor.hpp>
#include <Utils/Constants.hpp>

Diamond::Diamond(Point center, int horizontalDiagonal, int verticalDiagonal,
    Color outlineColor, Color fillColor)
    : center(center), outlineColor(outlineColor), fillColor(fillColor)
{
    this->horizontalDiagonal = horizontalDiagonal;
    this->verticalDiagonal = verticalDiagonal;
}

Diamond::~Diamond()
{

}

Point Diamond::GetCenterPoint() const
{
    return center;
}

int Diamond::GetHorizontalDiagonal() const
{
    return horizontalDiagonal;
}

int Diamond::GetVerticalDiagonal() const
{
    return verticalDiagonal;
}

Color Diamond::GetOutlineColor() const
{
    return outlineColor;
}

Color Diamond::GetFillColor() const
{
    return fillColor;
}

void Diamond::Accept(ShapeVisitor& visitor) const
{
    visitor.Visit(*this);
}

std::ostream& operator<<(std::ostream& os, Diamond const& diamond)
{
    return os << ShapeNames::Diamond
        << " " << diamond.center
        << " " << std::to_string(diamond.horizontalDiagonal)
        << " " << std::to_string(diamond.verticalDiagonal)
        << " " << diamond.outlineColor
        << " " << diamond.fillColor;
}
