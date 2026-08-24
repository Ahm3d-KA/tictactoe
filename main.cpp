#include "board.h"
#include "game.h"
#include "tile.h"
#include <iostream>
#include <stdexcept>
int main()
{
    Board b{Board::getInstance()};
    while (true)
    {
        std::cout << "\n\n\n\n\n" << b;
        // Coordinate coord{8};
        // b.makeMove(coord, Tile::State::cross);
        //
        // Coordinate coord2{6};
        // b.makeMove(coord2, Tile::State::cross);
        // b.makeMove(coord, Tile::State::cross);
        // b.makeMove(coord, Tile::State::cross);
        // std::cout << b;

        Tile::State playerTurn{Tile::State::nought};
        bool playOn{true};
        while (playOn)
        {
            if (playerTurn == Tile::State::nought)
            {
                playerTurn = Tile::State::cross;
            }
            else
            {
                playerTurn = Tile::State::nought;
            }

            int num{Game::HandleUserInput(playerTurn)};
            try
            {

                b.makeMove(Coordinate{num}, playerTurn);
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what();
                if (playerTurn == Tile::State::nought)
                {
                    playerTurn = Tile::State::cross;
                }
                else
                {
                    playerTurn = Tile::State::nought;
                }
                continue;
            }
            switch (b.gameOver(playerTurn))
            {
            case GameState::crossesWin:
                std::cout << "crosses win!\n";
                playOn = false;
                break;
            case GameState::noughtsWin:
                std::cout << "noughts win!\n";
                playOn = false;
                break;
            case GameState::draw:
                std::cout << "c'est un match nul :(\n";
                playOn = false;
                break;
            case GameState::ongoing:
                break;
            }
            std::cout << b;
        }
        b.erase();
    }

    return 0;
    // Tile tile1{};
    // tile1.setToNought();
    // std::cout << tile1;
    // tile1.setToCross();
    // std::cout << tile1;
}
