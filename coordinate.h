#include "board.h"
#include <array>
#include <ostream>
class Coordinate
{
  private:
    enum class CoordinateEnum
    {
        topLeft,
        topMiddle,
        topRight,
        middleLeft,
        middleMiddle,
        middleRight,
        bottomLeft,
        bottomMiddle,
        bottomRight,
    };
    std::array<std::pair<int, int>, gGridSize> mCoordinateGrid{{{0, 0}}};
    CoordinateEnum mCoordinate{};

  public:
    Coordinate(int number);
    friend std::ostream& operator<<(std::ostream& out,
                                    const Coordinate& coordinate);
};
