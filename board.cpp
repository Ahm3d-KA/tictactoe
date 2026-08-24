#include "board.h"
#include <cassert>
#include <cstddef>
#include <iostream>
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
    assert(((state == Tile::State::cross) || (state == Tile::State::nought)) &&
           "only put in a nought or cross when querying GameOver()\n");
    if (mNumMoves < gMinMovesForWin)
        return GameState::ongoing;
    // loop over the key tiles and check if game has been won
    for (auto [x, y] : keyTiles)
    {
        if (mGrid[y][x].getState() == state)
        {
            assert(
                (y <= 2) &&
                "naughty naughty asserty caught you tryna sneek in weird y\n");
            assert(x <= 2 && "x not less than 2 in assert\n");
            auto [t1, t2] = twoAdjacentTiles(Coordinate{x, y});
            // std::cerr << "ADJACENT: " << mGrid[y][x] << " next to " << t1
            // << " next to " << t2 << "\n";
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
        [[fallthrough]];
    default:
        return diagWin;
    }
    throw std::runtime_error("can't get here");
}

std::pair<Tile&, Tile&> Board::twoAdjacentTiles(const Coordinate& coordinate)
{
    switch (coordinate.getCoordinate())
    {
    case Coordinate::CoordinateEnum::bottomMiddle:
        return {mGrid[2][0], mGrid[2][2]};

    case Coordinate::CoordinateEnum::middleLeft:
        return {mGrid[0][0], mGrid[2][0]};
    case Coordinate::CoordinateEnum::middleRight:
        return {mGrid[0][2], mGrid[2][2]};
    case Coordinate::CoordinateEnum::topMiddle:
        return {mGrid[0][0], mGrid[0][2]};
    default:
        throw std::invalid_argument(
            "should only be giving the special values to twAdjacentTiles()\n");
    }
}

GameState Board::checkDiagonals()
{
    // if any diagonal has them all match up
    if ((mGrid[0][0].getState() == mGrid[1][1].getState() &&
         mGrid[1][1].getState() == mGrid[2][2].getState()) ||
        (mGrid[2][0].getState() == mGrid[1][1].getState() &&
         mGrid[1][1].getState() == mGrid[0][2].getState()))
    {
        switch (mGrid[1][1].getState())
        {
        case Tile::State::cross:
            return GameState::crossesWin;
        case Tile::State::nought:
            return GameState::noughtsWin;
        default:
            return GameState::ongoing;
        }
    }
    return GameState::ongoing;
}

constexpr std::array<std::array<Tile, gGridSize>, gGridSize> gGridCopy{};
void Board::erase()
{
    mNumMoves = 0;
    mGrid = gGridCopy;
}
