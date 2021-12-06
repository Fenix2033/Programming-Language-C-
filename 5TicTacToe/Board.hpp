//
//  HerniDeska.hpp
//  CPP_cviceni05_piskvorky
//
//  Created by David Procházka on 25/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#ifndef HerniDeska_hpp
#define HerniDeska_hpp

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Position.hpp"

namespace TicTacToe {
    template<class T>
    class Board {
    private:
        std::vector<std::vector<T>> board;
        char defaultItem;
    public:
        Board(unsigned int width, unsigned int height, T defaultItem);

        T at(Position position) const;

        unsigned int getWidth() const;

        unsigned int getHeight() const;

        bool canBeInserted(Position position) const;

        void insert(Position position, T item);

        void print() const;

        void popRow() noexcept(false);

        void popColumn() noexcept(false);

        void appendRow(T defaultItem);

        void appendColumn(T defaultItem);

        // TODO homework: methods for adding and removing column at any given index (not just from the end)
    };
}


template<class T>
TicTacToe::Board<T>::Board(unsigned int width, unsigned int height, T defaultItem) {
    this->defaultItem = defaultItem;
    std::vector<T> row(width, defaultItem); // [_,_,_,_,_]
    std::vector<std::vector<T>> matrix(height, row); // [_,_,_,_,_], [_,_,_,_,_], [_,_,_,_,_]
    board = matrix;
}

template<class T>
T TicTacToe::Board<T>::at(Position position) const {
    return board.at(position.row).at(position.column);
}


template<class T>
unsigned int TicTacToe::Board<T>::getWidth() const {
    return board.at(0).size();
}

template<class T>
unsigned int TicTacToe::Board<T>::getHeight() const {
    return board.size();
}

template<class T>
bool TicTacToe::Board<T>::canBeInserted(TicTacToe::Position position) const {
    return (
            position.row >= 0 and position.row < board.size() and
            position.column >= 0 and position.column < board.at(position.row).size() and
            board.at(position.row).at(position.column) == defaultItem
    );
}

template<class T>
void TicTacToe::Board<T>::insert(Position position, T item) {
    board.at(position.row).at(position.column) = item;
}

template<class T>
void TicTacToe::Board<T>::print() const {
//    for (int i; i < board.size(); i++) {
//        auto row = board.at(i);
//        ...
//    }

    //  ~
    // [_,_,_,_,_]

    for (auto rowPtr = board.begin(); rowPtr < board.end(); rowPtr++) {
        std::vector<T> row = *rowPtr;
        for (auto columnPtr = row.begin(); columnPtr < row.end(); columnPtr++) {
            std::cout << *columnPtr << " ";
        }
        std::cout << std::endl;
    }

//    for (auto &row: board) {
//        for (auto &column: row) {
//
//        }
//    }
}

template<class T>
void TicTacToe::Board<T>::popRow() noexcept(false) {
    if (board.size() > 5) {
        board.pop_back();
    } else {
        throw std::length_error("Uz mame jen jeden row, nelze odebrat");
    }
}

template<class T>
void TicTacToe::Board<T>::popColumn() noexcept(false) {
    if ((board.size() > 0) and (board.at(0).size() > 5)) {
        for (auto &row: board) {
            row.pop_back();
        }
    } else {
        throw std::length_error("Uz mame jen jeden column nebo neni row, nelze odebrat");
    }
}

template<class T>
void TicTacToe::Board<T>::appendRow(const T defaultItem) {
    // lze i podminkou
    try {
        unsigned int width = board.at(0).size();
        std::vector<T> row(width, defaultItem);
        board.push_back(row);
    } catch (std::out_of_range &ex) {
        throw std::length_error("nemam zadny row na odvozeni sirky");
    }
}

template<class T>
void TicTacToe::Board<T>::appendColumn(const T defaultItem) {
    for (auto &row:board) {
        row.push_back(defaultItem);
    }
}


#endif /* HerniDeska_hpp */
