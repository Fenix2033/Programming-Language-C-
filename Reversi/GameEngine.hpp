//
//  GameEngine.hpp
//  cv5_reversi
//
//  Created by David Procházka on 14/10/2021.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <iostream>
#include <fstream>
#include "Size.hpp"
#include "Position.hpp"
#include "GameDesk.hpp"

class GameEngine {
    GameDesk<std::string>* m_desk;
    std::string m_filename;
    
public:
    GameEngine(const Size size, const std::string filename);
    void play();
private:
    Position getUserInput(const std::string symbol) const;
    bool isWithinDesk(const Position position) const;
    bool isPositionEmpty(const Position position) const;
    void insertMove(const Position position, const std::string symbol);
    bool boolCheckFifth(const Position position) const;
    std::string switchUser() const;
    void saveDesk() const throw (std::invalid_argument);
};


#endif /* GameEngine_hpp */
