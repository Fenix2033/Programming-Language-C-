//
// Created by xkudla on 26/10/2021.
//

#include "Game.h"

#include "Map.h"
#include <iostream>

Game::Game(const std::string& mapFileName) {
    m_mapFileName = mapFileName;
    m_map = new Map();
}

void Game::printIntroduction() const {
    std::cout << "Game started." << std::endl;
}

void Game::printOptions() const {
    std::cout << "Press char" << std::endl;
}

Position Game::waitForInput() const{
    Position position{};

    do {
        std::cout << "Enter row: ";
        std::cin >> position.row;
        std::cout << "Enter column: ";
        std::cin >> position.column;
    } while (!m_map->canBeInserted(position));

    return position;
}

void Game::printEnd() const {
    std::cout << "Game ended" << std::endl;
}



void Game::start() {
    m_map->loadFromFile(m_mapFileName);
    printIntroduction();

    while (true) {
        m_map->print();
        printOptions();
        Position position = waitForInput();
        m_map->insert(position);
    }
}

