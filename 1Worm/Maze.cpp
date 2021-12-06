//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Maze.h"
#include <iostream>

Maze::Maze() {
    worm = new Worm();
    mazePlan = std::array<std::array<char, 5>, 5>();

    for (auto &row: mazePlan) { // auto -> array<char, 5>
        for (auto &column: row) { // auto -> char
            column = '-';
        }
    }
}

void Maze::print() const {
    for (int y = 0; y < mazePlan.size(); y++) {
        for (int x = 0; x < mazePlan.at(y).size(); x++) {
            if (worm->getPosition().x == x and worm->getPosition().y == y) {
                std::cout << Worm::symbol;
            } else {
                std::cout << mazePlan.at(x).at(y);
            }
        }
        std::cout << std::endl;
    }
}

void Maze::moveWorm(const int x, const int y) {
    Position position = worm->getPosition();
    worm->setPosition(position.x + x, position.y + y);
}

bool Maze::checkDirection(const int x, const int y) const {
    int newX = worm->getPosition().x + x;
    int newY = worm->getPosition().y + y;

    return (
        newX >= 0 and
        newX < mazePlan.at(0).size() and
        newY >= 0 and
        newY < mazePlan.size()
    );
}