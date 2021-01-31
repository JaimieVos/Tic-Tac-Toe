#include "game.h"

int main()
{
    Game game;

    while (game.isPlaying())
    {
        game.playerTurn();
    }
}