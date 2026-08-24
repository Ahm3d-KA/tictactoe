#include "coordinate.h"
#include "gameState.h"
#include "tile.h"
#pragma once
#include <array>

#include <ostream>
static constexpr int gGridSize{3};
class Board
{
  private:
    std::array<std::array<Tile, gGridSize>, gGridSize> mGrid{};
    int mNumMoves{0};
    std::pair<Tile&, Tile&> twoAdjacentTiles(const Coordinate& coordinate);
    GameState checkDiagonals();

  public:
    friend std::ostream& operator<<(std::ostream& out, const Board& board);
    void makeMove(const Coordinate& coordinate, Tile::State state);
    GameState gameOver(Tile::State state);
    void erase();
    // singleton
    static Board& getInstance()
    {
        static Board board{};
        return board;
    }

  private:
    Board() {}
};
