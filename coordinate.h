#include <array>
#include <cstddef>
#include <ostream>
class Coordinate
{
  public:
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

  private:
    static constexpr std::array<std::string, 9> names{{
        "topLeft",
        "topMiddle",
        "topRight",
        "middleLeft",
        "middleMiddle",
        "middleRight",
        "bottomLeft",
        "bottomMiddle",
        "bottomRight",
    }};
    static constexpr std::array<std::pair<std::size_t, std::size_t>, 9>
        mCoordinateGrid{{{0, 0},
                         {0, 1},
                         {0, 2},
                         {1, 0},
                         {1, 1},
                         {1, 2},
                         {2, 0},
                         {2, 1},
                         {2, 2}}};

    CoordinateEnum mCoordinate{};

  public:
    CoordinateEnum getCoordinate() const { return mCoordinate; }
    std::size_t y() const;
    std::size_t x() const;
    Coordinate(int number);
    Coordinate(std::size_t x, std::size_t y);
    friend std::ostream& operator<<(std::ostream& out,
                                    const Coordinate& coordinate);
};
