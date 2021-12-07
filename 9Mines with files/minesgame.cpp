#include "minesgame.h"

MinesGame::MinesGame(QObject *parent) : QObject(parent)
{
    //m_mines.resize(36);
    /*
    m_mines = {
        0, 0, 0, 0, 0, 0,
        1, 1, 2, 1, 1, 0,
        1, 9, 2, 9, 1, 0,
        1, 1, 2, 1, 1, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    };
    */
    m_mines = FileManager::loadXml();
}

int MinesGame::getMineCount(int index){
    return m_mines.at(index);
}
