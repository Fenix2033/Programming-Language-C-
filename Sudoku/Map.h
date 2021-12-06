//
// Created by xkudla on 26/10/2021.
//

#ifndef SUDOKU_MAP_H
#define SUDOKU_MAP_H

#include <array>
#include <string>
#include "Position.h"

class Map {
public:
    static const int mapSize = 9;
    static const char Symbol = '0';

private:
    std::array<std::array<char, mapSize>, mapSize> m_map;
    char m_defaultItem = '0';

public:
    Map();
    void print() const;
    void loadFromFile(const std::string& fileName);
    Position getPosition();
    char at(Position position) const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    bool canBeInserted(Position position) const;
    void insert(Position position);
};


#endif //SUDOKU_MAP_H
