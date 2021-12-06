//
//  Matici.hpp
//  Test
//
//  Created by Vitalii Kudla on 27/10/2021.
//

#ifndef Matici_hpp
#define Matici_hpp

#include <array>
#include <string>
#include "Position.hpp"

class Matici {
public:
    static const int maticiSize = 4;
    static const char Symbol = 'F';

private:
    std::array<std::array<char, maticiSize>, maticiSize> m_matici;
    char m_defaultItem = '0';

public:
    Matici();
    void print() const;
    void loadFromFile(const std::string& fileName);
    void writeInFile(const std::string& fileName);
    Position getPosition();
    char at(Position position) const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    bool canBeInserted(Position position) const;
    void insert(Position position);
};


#endif /* Matici_hpp */
