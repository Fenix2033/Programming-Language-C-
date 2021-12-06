//
// Created by Ivo Pisařovic on 24/09/2020.
//

#ifndef UNTITLED_TESLA_H
#define UNTITLED_TESLA_H


#include "Position.h"

class Tesla {
private:
    Position position{};
    int battery = 10;
public:
    Tesla();
    static const int maxBattery = 10;
    static const char symbol = '@';
    Position getPosition();
    void setPosition(int x, int y);
    void charge();
    void discharge();
    void printBatteryInfo() const;
};


#endif //UNTITLED_TESLA_H
