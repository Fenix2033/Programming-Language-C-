//
// Created by xkudla on 26/10/2021.
//

#include "Map.h"
#include <iostream>
#include <fstream>

Map::Map(){
    m_map = std::array<std::array<char, mapSize>, mapSize>();
}

void Map::print() const {
    for (int y = 0; y < m_map.size(); y++) {
        for (int x = 0; x < m_map.at(y).size(); x++) {
                std::cout << m_map.at(x).at(y) << " ";
        }
        std::cout << std::endl;
    }

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
            m_map.at(x).at(y) = element;
            y++;
        }

        x++;
    }
}

char Map::at(Position position) const{

}

unsigned int Map::getWidth() const{
    return m_map.at(0).size();
}

unsigned int Map::getHeight() const{
    return m_map.size();
}

bool Map::canBeInserted(Position position) const{
    return (
            position.row >= 0 and position.row < m_map.size() and
            position.column >= 0 and position.column < m_map.at(position.row).size() and
            m_map.at(position.row).at(position.column) == m_defaultItem
    );
}

void Map::insert(Position position){
    std::cout << "Input number 0 - 9: " << std::endl;
    char item;
    std::cin >> item;
    m_map.at(position.row).at(position.column) = item;
}