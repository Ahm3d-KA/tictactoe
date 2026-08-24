#include "game.h"
#include "tile.h"
#include <exception>
#include <iostream>
#include <stdexcept>
int Game::HandleUserInput(Tile::State state)
{
    while (true)
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
                "should only handle an input with nought or cross\n");
        }
        std::string input{};
        std::getline(std::cin, input);
        try
        {
            int num{std::stoi(input)};
            if (num < 0 || num >= 9)
            {
                throw std::out_of_range("Needs to be a number between 0 - 8\n");
            }
            return num;
        }
        catch (const std::out_of_range& e)
        {
            std::cout << e.what();
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << "im guessing fialed conversion\n";
        }
    }
}
