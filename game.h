#pragma once

class Game
{
private:
    bool checkWin() const;

    static constexpr int gridSize = 3;
    char grid[gridSize][gridSize];
    bool playing = true;
    bool player = 0;
    int turns = 0;

public:
    Game();
    void generateGrid();
    void drawGrid() const;
    void playerTurn();
    bool isPlaying() const;
};