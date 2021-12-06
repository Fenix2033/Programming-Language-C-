//
// Created by Ivo Pisařovic on 24/09/2020.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H


#include <array>
#include "Tesla.h"

class Map {
public:
    static const int mapSize = 6;
    static const char chargingStationSymbol = '+';
    static const char roadSymbol = '-';

private:
    Tesla* tesla;
    std::array<std::array<char, mapSize>, mapSize> map;

public:
    Map();
    void print() const;
    void printTeslaInfo() const;
    bool checkDirection(int x, int y) const;
    void moveTesla(int x, int y);
    void loadFromFile(const std::string& fileName);
};


#endif //UNTITLED_MAP_H
