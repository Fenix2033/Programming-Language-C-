#include "minegenerator.h"
#include <iostream>

MineGenerator::MineGenerator(QObject *parent) : QObject(parent)
{
    mines.resize(36);
    mines =
    {
        0, 0, 0, 0, 0, 0,
        1, 1, 2, 1, 1, 0,
        1, 9, 2, 9, 1, 0,
        1, 1, 2, 1, 1, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    };
}

int MineGenerator::getMineCount(int index){
    return mines.at(index);
}

int MineGenerator::getScore()
{
    return score;
}

void MineGenerator::increaseScore(int number)
{
    std::cout << "called C++ from QML" << std::endl;
    score += number;
    emit scoreChanged();
}



