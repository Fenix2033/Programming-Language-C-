//
//  GameEngine.cpp
//  cpp_cviceni5_piskvorky
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "GameEngine.hpp"
#include <algorithm>

TicTacToe::GameEngine::GameEngine() {
    board = new TicTacToe::Board<char>(10, 10, '_');
}

void TicTacToe::GameEngine::start() {
    // TODO homework: enable game of more than 2 players
    std::string winningPlayer;

    while (winningPlayer.empty()) {
        Position aPosition = playOneTurn("Ivo");

        if (checkFiveInRow(aPosition)) {
            winningPlayer = "Ivo";
            break;
        }

        Position bPosition = playOneTurn("David");

        if (checkFiveInRow(bPosition)) {
            winningPlayer = "David";
            break;
        }
    }

    std::cout << "Player " << winningPlayer << " won.";
}

TicTacToe::Position TicTacToe::GameEngine::waitForInput(const std::string &player) const {
    Position position{};

    std::cout << "It's player " << player << "'s turn now:" << std::endl;

    do {
        std::cout << "Enter row: ";
        std::cin >> position.row;
        std::cout << "Enter column: ";
        std::cin >> position.column;
    } while (!board->canBeInserted(position));

    return position;
}

TicTacToe::Position TicTacToe::GameEngine::playOneTurn(const std::string &player) noexcept(false) {
    board->print();
    Position position = waitForInput(player);
    board->insert(position, player.at(0));
    return position;
}

TicTacToe::GameEngine::~GameEngine() {
    delete board;
}

bool TicTacToe::GameEngine::checkFiveInRow(const Position position) const {
    unsigned int sameCount = 0u;
    char detectedChar = board->at(position);
    unsigned int startColumn = position.column - std::min(4u, position.column);
    unsigned int endColumn = std::min(position.column + 4, board->getWidth() - 1);

    for (unsigned int column = startColumn; column <= endColumn; column++) {
        if (board->at({position.row, column}) == detectedChar) {
            sameCount++;
            if (sameCount >= 5) {
                break;
            }
        } else {
            sameCount = 0;
        }
    }

    // TODO homework, checking also in other directions (vertical and diagonal)

    return sameCount >= 5;
}