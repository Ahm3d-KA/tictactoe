#include "tile.h"
#include <array>
#include <ostream>
constexpr int gGridSize{3};
class Square;
class Coordinate;
enum class GameState;
class Board
{
  private:
    std::array<std::array<Tile, gGridSize>, gGridSize> mGrid{};

  public:
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
    void makeMove(const Coordinate& coordinate);
    GameState gameOver();
    // singleton
    static Board& getInstance()
    {
        static Board board{};
        return board;
    }

  private:
    Board() {}
};
