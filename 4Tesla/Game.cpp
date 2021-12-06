//
// Created by Ivo Pisařovic on 01/10/2020.
//

#include "Game.h"

//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Map.h"
#include <iostream>

Game::Game(const std::string& mapFileName) {
    this->mapFileName = mapFileName;
    map = new Map();
}

void Game::printIntroduction() const {
    std::cout << "Game started." << std::endl;
}

void Game::printOptions() const {
    std::cout << "Press WASD to move the tesla." << std::endl;
}

char Game::waitForInput() const {
    char input;
    std::cin >> input;
    return input;
}

void Game::printEnd() const {
    std::cout << "Game ended" << std::endl;
}

void Game::start() {
    map->loadFromFile(mapFileName);
    printIntroduction();

    while (true) {
        map->printTeslaInfo();
        map->print();
        printOptions();
        char input = waitForInput();
        processInput(input);
    }
}

void Game::processInput(char input) {
    if (input == 'q') {
        printEnd();
        exit(0);
    } else if (input == 'a') {
        tryMovingTesla(-1, 0);
    } else if (input == 'd') {
        tryMovingTesla(1, 0);
    } else if (input == 'w') {
        tryMovingTesla(0, -1);
    } else if (input == 's') {
        tryMovingTesla(0, 1);
    } else {
        std::cout << "Unsupported option!" << std::endl;
    }
}

void Game::tryMovingTesla(int x, int y) {
    try {
        map->moveTesla(x, y);
    } catch (std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}





