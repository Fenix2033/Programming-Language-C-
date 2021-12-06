//
//  GameDesk.hpp
//  cv5_reversi
//
//  Created by David Procházka on 14/10/2021.
//

#ifndef GameDesk_hpp
#define GameDesk_hpp

#include <vector>
#include <iostream>
#include "Position.hpp"
#include "Size.hpp"

template<class T> class GameDesk {
    std::vector<std::vector<T>> m_desk;
    
public:
    GameDesk(const Size size, const T initValue);
    void setValue(const Position position, const T value) throw (std::out_of_range);
    T getValue(const Position position) const throw (std::out_of_range);
    void print() const;
    Size getSize() const;
};

template<class T> GameDesk<T>::GameDesk(const Size size, const T initValue){
    std::vector<std::vector<T>> desk(size.rows, std::vector<T>(size.cols, initValue));
    m_desk = desk;
}

template<class T> void GameDesk<T>::setValue(const Position position, const T value) throw (std::out_of_range){
    m_desk.at(position.row).at(position.col) = value;
}

template<class T> T GameDesk<T>::getValue(const Position position) const throw (std::out_of_range) {
    return m_desk.at(position.row).at(position.col);
}

template<class T> void GameDesk<T>::print() const{
    for (auto row: m_desk) {
        for (auto cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

template<class T> Size GameDesk<T>::getSize() const{
    unsigned int rows = m_desk.size();
    unsigned int cols = 0;
    if (rows>0){
        cols = m_desk.at(0).size();
    }
    return Size{rows, cols};
}


#endif /* GameDesk_hpp */
