//
// Created by Ivo Pisařovic on 24/09/2020.
//

#include <exception>
#include <iostream>
#include "Tesla.h"
#include "BatteryException.h"

Tesla::Tesla() {
    position = Position{3, 3};
}

Position Tesla::getPosition() {
    return position;
}

void Tesla::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

void Tesla::charge() {
    battery = maxBattery;
}

void Tesla::discharge() {
    if (battery > 0) {
        battery--;
    } else {
        throw BatteryException();
    }
}

void Tesla::printBatteryInfo() const {
    std::cout << "Battery level " << battery << std::endl;
}
