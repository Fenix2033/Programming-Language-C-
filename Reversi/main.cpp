//
//  main.cpp
//  cv5_reversi
//
//  Created by David Procházka on 14/10/2021.
//

#include <iostream>
#include "GameEngine.hpp"

int main(int argc, const char * argv[]) {
    GameEngine* reversi = new GameEngine(Size{5,10}, "/home/xkudla/Documents/GitHub C++/Reversi/save.txt");
    reversi->play();
    delete reversi;
    return 0;
}
