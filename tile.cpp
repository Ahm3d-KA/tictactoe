#include "tile.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
    switch (tile.state)
    {
    case Tile::State::cross:
        out << "X";
        break;
    case Tile::State::nought:
        out << "O";
        break;
    case Tile::State::empty:
        out << "-";
        break;
    }
    return out;
}
