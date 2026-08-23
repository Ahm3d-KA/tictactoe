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
    std::array<std::array<std::pair<std::size_t, std::size_t>, gGridSize>,
               gGridSize>
        mCoordinateGrid{{{{{0, 0}, {0, 1}, {0, 2}}},
                         {{{1, 0}, {1, 1}, {1, 2}}},
                         {{{2, 0}, {2, 1}, {2, 2}}}}};
    CoordinateEnum mCoordinate{};
    std::size_t y();
    std::size_t x();

  public:
    Coordinate(int number);
    friend std::ostream& operator<<(std::ostream& out,
                                    const Coordinate& coordinate);
};
