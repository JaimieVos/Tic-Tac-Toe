#include <iostream>
#include <string>
#include <math.h>
#include <limits>

#define GRID_SIZE 3

using namespace std;

class Game
{
private:
    bool checkWin();

    char grid[GRID_SIZE][GRID_SIZE];
    int position = 0;
    int player = 0;
    int turns = 0;

public:
    Game();
    void generateGrid();
    void drawGrid();
    void playerTurn();

    bool playing = true;
};

Game::Game()
{
    generateGrid();
}

void Game::generateGrid()
{
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            grid[x][y] = to_string(position).c_str()[0];
            position++;
        }
    }
}

void Game::drawGrid()
{
    cout << "---------" << endl;
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = 0; y < GRID_SIZE; y++)
        {
            cout << "|" << grid[x][y] << "|";
        }

        cout << endl << "---------" << endl;
    }
}

void Game::playerTurn()
{
    drawGrid();

    int input;
    cout << "Player " << player << " what position would you like to mark?: ";
    cin >> input;

    if (!cin || !(input >= 0 && input <= 8))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a valid position." << endl;
        return playerTurn();
    }

    int row = input / GRID_SIZE;
    int col = input % GRID_SIZE;

    if (grid[row][col] == 'x' || grid[row][col] == 'o')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter a valid position." << endl;
        return playerTurn();
    }
    else
    {
        grid[row][col] = (player) ? 'o' : 'x';
    }

    if (checkWin())
    {
        cout << "Player " << player << " has won!" << endl;
        playing = false;
    }
    else
    {
        player = (player) ? 0 : 1;

        turns++;
        if (turns == 9)
        {
            cout << "The game ended in a draw" << endl;
            playing = false;
        }
    }
}

bool Game::checkWin()
{
    char mark = (player) ? 'o' : 'x';

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

int main()
{
    Game game;

    while (game.playing)
    {
        game.playerTurn();
    }
}