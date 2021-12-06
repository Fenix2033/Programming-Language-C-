//
//  GameEngine.h
//  cpp_cviceni5_piskvorky
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#ifndef __cpp_cviceni4_piskvorky__HerniEngine__
#define __cpp_cviceni4_piskvorky__HerniEngine__

#include <iostream>
#include "Board.hpp"

namespace TicTacToe {
    class GameEngine {

    private:
        Board<char> *board;

    public:
        GameEngine();

        void start();

        ~GameEngine();

    private:
        Position waitForInput(const std::string &player) const;

        Position playOneTurn(const std::string &player) noexcept(false);

        bool checkFiveInRow(Position position) const;

    };
}
#endif /* defined(__cpp_cviceni4_piskvorky__HerniEngine__) */
