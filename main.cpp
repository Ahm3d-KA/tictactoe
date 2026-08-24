#include "board.h"
#include "tile.h"
#include <iostream>
int main()
{
    Board b{Board::getInstance()};
    std::cout << b;

    // Tile tile1{};
    // tile1.setToNought();
    // std::cout << tile1;
    // tile1.setToCross();
    // std::cout << tile1;
}
