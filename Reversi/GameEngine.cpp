//
//  GameEngine.cpp
//  cv5_reversi
//
//  Created by David Procházka on 14/10/2021.
//

#include "GameEngine.hpp"

GameEngine::GameEngine(const Size size, const std::string filename){
    m_desk = new GameDesk<std::string>(size, ".");
    m_filename = filename;
}

void GameEngine::play(){
    m_desk->print();
    saveDesk();
}

Position GameEngine::getUserInput(const std::string symbol) const{
    return Position{0,0};
}

bool GameEngine::isWithinDesk(const Position position) const{
    return false;
}

bool GameEngine::isPositionEmpty(const Position position) const{
    return false;
}

void GameEngine::insertMove(const Position position, const std::string symbol){
    
}

bool GameEngine::boolCheckFifth(const Position position) const{
    return false;
}

std::string GameEngine::switchUser() const{
    return "X";
}

void GameEngine::saveDesk() const throw (std::invalid_argument){
    // zkus otevrit soubor, kdyz se nepovede, vyhod vyjimku
    // pokud ano, tak postupne projdi pole a uloz do souboru hodnoty
    std::ofstream file(m_filename);
    Size deskSize = m_desk->getSize();
    
    if(file.is_open()){
        for(unsigned int row=0; row<deskSize.rows; ++row){
            for(unsigned int col=0; col<deskSize.cols; ++col){
                file << m_desk->getValue(Position{row, col});
            }
            file << std::endl;
        }
        
        file.close();
    } else {
        throw std::invalid_argument("Cannot open the file for saving");
    }
}
