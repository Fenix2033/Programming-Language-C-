//
//  Matici.cpp
//  Test
//
//  Created by Vitalii Kudla on 27/10/2021.
//

#include "Matici.hpp"
#include <iostream>
#include <fstream>

Matici::Matici(){
    m_matici = std::array<std::array<char, maticiSize>, maticiSize>();
}

void Matici::print() const {
    for (int y = 0; y < m_matici.size(); y++) {
        for (int x = 0; x < m_matici.at(y).size(); x++) {
                std::cout << m_matici.at(x).at(y) << " ";
        }
        std::cout << std::endl;
    }

}

void Matici::loadFromFile(const std::string& fileName) {
    std::ifstream in(fileName);
    std::string line;

    if (!in.is_open()) {
        throw std::invalid_argument("File " + fileName + " cannot be opened!");
    }

    int x = 0;

    while(getline(in, line)){
        int y = 0;

//     if (x >= maticiSize || line.size() != maticiSize) {
//           throw std::out_of_range("Matici in file is not in expected size of " + std::to_string(maticiSize) + "!");
//    }

        for (auto &element: line) {
            m_matici.at(x).at(y) = element;
            y++;
        }

        x++;
    }
}

void writeInFile(const std::string& fileName){
    
    std::ofstream out(fileName);
    std::string line;
    
//    for (int y = 0; y < m_matici.size(); y++) {
//        for (int x = 0; x < m_matici.at(y).size(); x++) {
//                out << m_matici.at(x).at(y);
//        }
//        std::cout << std::endl;
//    }
//
    out.close();
}

unsigned int Matici::getWidth() const{
    return m_matici.at(0).size();
}

unsigned int Matici::getHeight() const{
    return m_matici.size();
}

bool Matici::canBeInserted(Position position) const{
    if (position.row >= 0 and position.row < m_matici.size() and
        position.column >= 0 and position.column < m_matici.at(position.row).size() and
        m_matici.at(position.row).at(position.column) == 'R' or
        m_matici.at(position.row).at(position.column) == 'O'){
        std::cout << "Table has been order 'R' or 'O'" << std::endl;
        return false;
    }
    
    else if (position.row >= 0 and position.row < m_matici.size() and
             position.column >= 0 and position.column < m_matici.at(position.row).size()){
        return true;
        
    } else {
        std::cout << "Wrong number table" << std::endl;
        return false;
    }
}

void Matici::insert(Position position){
    std::cout << "Input char R, O or F: " << std::endl;
    char item;
    std::cin >> item;
    if (item == 'R' or item == 'O' or item == 'F'){
        m_matici.at(position.row).at(position.column) = item;
    } else {
        std::cout << "Wrong input" << std::endl;
    }
    
}
