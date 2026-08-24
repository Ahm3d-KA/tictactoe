#include "board.h"
#include <cassert>
#include <cstddef>
#include <stdexcept>

std::ostream& operator<<(std::ostream& out, const Board& board)
{
    for (const std::array<Tile, gGridSize>& row : board.mGrid)
    {
        for (const Tile& tile : row)
        {
            out << " " << tile;
        }
        out << "\n";
    }
    return out;
}

void Board::makeMove(const Coordinate& coordinate, Tile::State state)
{
    assert(state != Tile::State::empty && "state should not be empty here");
    if (mGrid[coordinate.y()][coordinate.x()].getState() != Tile::State::empty)
    {
        throw std::invalid_argument("this spot is taken\n");
    }
    ++mNumMoves;
    mGrid[coordinate.y()][coordinate.x()].setState(state);
}
static constexpr int gMinMovesForWin{5};
constexpr std::array<std::pair<std::size_t, std::size_t>, 4> keyTiles{
    {{0, 1}, {1, 0}, {2, 1}, {1, 2}}};
GameState Board::gameOver(Tile::State state)
{
    assert(state == Tile::State::cross ||
           state == Tile::State::nought &&
               "only put in a nought or cross when querying GameOver()\n");
    if (mNumMoves < gMinMovesForWin)
        return GameState::ongoing;
    // loop over the key tiles and check if game has been won
    for (auto [x, y] : keyTiles)
    {
        if (mGrid[y][x].getState() == state)
        {
            auto [t1, t2] = twoAdjacentTiles(Coordinate{x, y});
            if (mGrid[y][x].getState() == t1.getState() &&
                t1.getState() == t2.getState())
            {
                switch (state)
                {
                case Tile::State::cross:
                    return GameState::crossesWin;
                case Tile::State::nought:
                    return GameState::noughtsWin;
                default:
                    throw std::invalid_argument(
                        "should only call gameOver with a nought or cross "
                        "state\n");
                }
            }
            // TODO: work from here, look at two adjacent tiles and see if they
            // all pair up
            //  need a special case for stuff passing through the middle
        }
    }
    GameState diagWin{checkDiagonals()};
    assert(diagWin != GameState::draw);
    switch (diagWin)
    {
    case GameState::ongoing:
        if (mNumMoves == 9)
            return GameState::draw;
    default:
        return diagWin;
    }
}
