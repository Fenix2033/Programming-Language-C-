#include "Map.h"
#include "Game.h"

int main() {
    Game* game = new Game("map.txt");
    game->start();

    return 0;
}
