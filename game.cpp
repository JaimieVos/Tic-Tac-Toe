#include "game.h"
#include <iostream>
#include <string>
#include <cmath>
#include <limits>

Game::Game()
{
    generateGrid();
}

void Game::generateGrid()
{
    char position = 0;
    for (int x = 0; x < gridSize; x++)
    {
        for (int y = 0; y < gridSize; y++)
        {
            grid[x][y] = std::to_string(position).c_str()[0];
            position++;
        }
    }
}

void Game::drawGrid() const
{
    std::cout << "---------\n";
    for (int x = 0; x < gridSize; x++)
    {
        for (int y = 0; y < gridSize; y++)
        {
            std::cout << "|" << grid[x][y] << "|";
        }

        std::cout << "\n---------\n";
    }
}

void Game::playerTurn()
{
    drawGrid();

    int row, col;
    while (true)
    {
        int input;
        std::cout << "Player " << player << " what position would you like to mark?: ";
        std::cin >> input;

        if (!std::cin || !(input >= 0 && input < gridSize * gridSize))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter a valid position.\n";
            continue;
        }

        row = input / gridSize;
        col = input % gridSize;

        if (grid[row][col] == 'x' || grid[row][col] == 'o')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Please enter a valid position.\n";
            continue;
        }

        break;
    }

    grid[row][col] = (player) ? 'o' : 'x';

    if (checkWin())
    {
        std::cout << "Player " << player << " has won!\n";
        playing = false;
    }
    else
    {
        player = (player) ? 0 : 1;

        turns++;
        if (turns == gridSize * gridSize)
        {
            std::cout << "The game ended in a draw\n";
            playing = false;
        }
    }
}

bool Game::checkWin() const
{
    const char mark = (player) ? 'o' : 'x';

    // Horizontal lines
    if (grid[0][0] == mark && grid[0][1] == mark && grid[0][2] == mark) { return true; }
    if (grid[1][0] == mark && grid[1][1] == mark && grid[1][2] == mark) { return true; }
    if (grid[2][0] == mark && grid[2][1] == mark && grid[2][2] == mark) { return true; }

    // Vertical lines
    if (grid[0][0] == mark && grid[1][0] == mark && grid[2][0] == mark) { return true; }
    if (grid[0][1] == mark && grid[1][1] == mark && grid[2][1] == mark) { return true; }
    if (grid[0][2] == mark && grid[1][2] == mark && grid[2][2] == mark) { return true; }

    // Diagonal lines
    if (grid[0][0] == mark && grid[1][1] == mark && grid[2][2] == mark) { return true; }
    if (grid[0][2] == mark && grid[1][1] == mark && grid[2][0] == mark) { return true; }

    return false;
}

bool Game::isPlaying() const
{
    return this->playing;
}