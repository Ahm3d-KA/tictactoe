#include "game.h"
#include "tile.h"
#include <iostream>
#include <stdexcept>
int Game::handleUserInput(Tile::State state)
{
    switch (state)
    {
    case Tile::State::cross:
        std::cout << "player 1, enter an input: ";
        break;
    case Tile::State::nought:
        std::cout << "player 2, enter an input: ";
        break;
    default:
        throw std::invalid_argument(
            "should only handle an input with nought or cross");
    }
    std::string input{};
    std::getline(std::cin, input);
    try
    {
        int num{std::stoi(input)};
        if (num < 0 || num >= 9)
        {
            throw std::out_of_range("Needs to be a number between 0 - 8");
        }
        return num;
    }
    catch (...)
    {
        throw;
    }
}
