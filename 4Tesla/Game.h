//
// Created by Ivo Pisařovic on 01/10/2020.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include <string>
#include "Map.h"

class Game {
private:
    std::string mapFileName;
    Map* map;
    void printIntroduction() const;
    void printOptions() const;
    char waitForInput() const;
    void printEnd() const;
    void processInput(char input);
    void tryMovingTesla(int x, int y);

public:
    void start();
    Game(const std::string& mapFileName);
};


#endif //UNTITLED_GAME_H
