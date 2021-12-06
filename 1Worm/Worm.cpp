//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include "Worm.h"

Worm::Worm() {
    position = Position{3, 3};
}

Position Worm::getPosition() {
    return position;
}

void Worm::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}
