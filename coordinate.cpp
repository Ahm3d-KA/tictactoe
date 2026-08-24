#include "coordinate.h"
#include <cstddef>
#include <stdexcept>
std::size_t Coordinate::y() const
{
    auto [y, _] = mCoordinateGrid[static_cast<std::size_t>(mCoordinate)];
    return y;
}
std::size_t Coordinate::x() const
{
    auto [_, x] = mCoordinateGrid[static_cast<std::size_t>(mCoordinate)];
    return x;
}
Coordinate::Coordinate(int number)
{
    mCoordinate = static_cast<Coordinate::CoordinateEnum>(number);
}
Coordinate::Coordinate(std::size_t x, std::size_t y)
{
    if (y == 0)
    {
        if (x == 0)
        {
            mCoordinate = CoordinateEnum::topLeft;
        }
        else if (x == 1)
        {
            mCoordinate = CoordinateEnum::topMiddle;
        }
        else if (x == 2)
        {
            mCoordinate = CoordinateEnum::topRight;
        }
    }
    else if (y == 1)
    {
        if (x == 0)
        {
            mCoordinate = CoordinateEnum::middleLeft;
        }
        else if (x == 1)
        {
            mCoordinate = CoordinateEnum::middleMiddle;
        }
        else if (x == 2)
        {
            mCoordinate = CoordinateEnum::middleRight;
        }
    }
    else if (y == 2)
    {
        if (x == 0)
        {
            mCoordinate = CoordinateEnum::bottomLeft;
        }
        else if (x == 1)
        {
            mCoordinate = CoordinateEnum::bottomMiddle;
        }
        else if (x == 2)
        {
            mCoordinate = CoordinateEnum::bottomRight;
        }
    }
    throw std::out_of_range(
        "y needs to be in range 0 - 2 to make a coordinate\n");
}
std::ostream& operator<<(std::ostream& out, const Coordinate& coordinate)
{
    out << "x = " << coordinate.x() << " y = " << coordinate.y() << "\n";
    out << coordinate.names[static_cast<std::size_t>(coordinate.mCoordinate)]
        << "\n";
    return out;
}
