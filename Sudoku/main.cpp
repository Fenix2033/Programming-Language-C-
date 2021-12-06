#include "Map.h"
#include "Game.h"

int main() {
    Game* game = new Game("/home/xkudla/Documents/GitHub C++/Sudoku/map.txt");
    game->start();

    return 0;
}
