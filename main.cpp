#include "board.h"
#include "tile.h"
#include <iostream>
int main()
{
    Board b{Board::getInstance()};
    std::cout << b;
    Coordinate coord{8};
    b.makeMove(coord, Tile::State::cross);

    Coordinate coord2{6};
    b.makeMove(coord2, Tile::State::cross);
    // b.makeMove(coord, Tile::State::cross);
    // b.makeMove(coord, Tile::State::cross);
    std::cout << b;

    // Tile tile1{};
    // tile1.setToNought();
    // std::cout << tile1;
    // tile1.setToCross();
    // std::cout << tile1;
}
