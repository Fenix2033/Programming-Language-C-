//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Map.h"
#include <iostream>
#include <fstream>

Map::Map() {
    tesla = new Tesla();
    map = std::array<std::array<char, mapSize>, mapSize>();
}

void Map::print() const {
    for (int y = 0; y < map.size(); y++) {
        for (int x = 0; x < map.at(y).size(); x++) {
            if (tesla->getPosition().x == x and tesla->getPosition().y == y) {
                std::cout << " " << Tesla::symbol << " ";
            } else {
                std::cout << " " << map.at(x).at(y) << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Map::moveTesla(const int x, const int y) {
    if (!checkDirection(x, y)) {
        throw std::out_of_range("Cannot go behind the map!");
    }

    Position position = tesla->getPosition();

    if (map.at(position.x + x).at(position.y + y) == chargingStationSymbol) {
        tesla->charge();
    } else {
        tesla->discharge();
    }

    tesla->setPosition(position.x + x, position.y + y);
}

bool Map::checkDirection(const int x, const int y) const {
    int newX = tesla->getPosition().x + x;
    int newY = tesla->getPosition().y + y;

    return (
        newX >= 0 and
        newX < map.at(0).size() and
        newY >= 0 and
        newY < map.size()
    );
}

void Map::loadFromFile(const std::string& fileName) {
    std::ifstream in(fileName);
    std::string line;

    if (!in.is_open()) {
        throw std::invalid_argument("File " + fileName + " cannot be opened!");
    }

    int x = 0;

    while(getline(in, line)){
        int y = 0;

        if (x >= mapSize || line.size() != mapSize) {
            throw std::out_of_range("Map in file is not in expected size of " + std::to_string(mapSize) + "!");
        }

        for (auto &element: line) {
            map.at(x).at(y) = element;
            y++;
        }

        x++;
    }
}

void Map::printTeslaInfo() const {
    tesla->printBatteryInfo();
}
