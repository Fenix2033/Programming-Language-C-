//
// Created by xkudla on 26/10/2021.
//

#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include <string>
#include "Map.h"

class Game {
private:
    std::string m_mapFileName;
    Map* m_map;
    void printIntroduction() const;
    void printOptions() const;
    void printEnd() const;
    void processInput(char input);
    void tryMovingTesla(int x, int y);

public:
    void start();
    Game(const std::string& mapFileName);
    ~Game();

private:
    Position waitForInput() const;
    Position playOneTurn(const std::string &player) noexcept(false);
    bool checkFiveInRow(Position position) const;
};


#endif //SUDOKU_GAME_H
