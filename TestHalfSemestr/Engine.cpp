//
//  Engine.cpp
//  Test
//
//  Created by Vitalii Kudla on 27/10/2021.
//

#include "Engine.hpp"
#include <iostream>

Engine::Engine(const std::string& maticiFileName) {
    m_maticiFileName = maticiFileName;
    m_matici = new Matici();
}

void Engine::printIntroduction() const {
    std::cout << "Program started." << std::endl;
}

void Engine::printOptions() const {
    std::cout << "Press char" << std::endl;
}

Position Engine::waitForInput() const{
    Position position{};
    int table = 0;

    do {
        std::cout << "Enter table: ";
        std::cin >> table;
        if (table > 0 and table < 5){
            position.row = table - 1;
            position.column = 0;
        }
        
        else if (table > 4 and table < 9){
            position.row = table - 5;
            position.column = 1;
        }
        
        else if (table > 8 and table < 13){
            position.row = table - 9;
            position.column = 2;
        }
        
        else if (table > 12 and table < 17){
            position.row = table - 13;
            position.column = 3;
        }

        else if (table == 0){
            exit(0);
        }
        
    } while (!m_matici->canBeInserted(position));

    return position;
}

void Engine::printEnd() const {
    std::cout << "Program ended" << std::endl;
}



void Engine::start() {
    m_matici->loadFromFile(m_maticiFileName);
    printIntroduction();

    while (true) {
        m_matici->print();
        printOptions();
        Position position = waitForInput();
        m_matici->insert(position);
    }
}
