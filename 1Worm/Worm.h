//
// Created by Ivo Pisařovic on 24/09/2020.
//

#ifndef UNTITLED_WORM_H
#define UNTITLED_WORM_H


#include "Position.h"

class Worm {
private:
    Position position{};
public:
    Worm();
    static const char symbol = '@';
    Position getPosition();
    void setPosition(int x, int y);
};


#endif //UNTITLED_WORM_H
