//
// Created by Ivo Pisařovic on 15/10/2020.
//

#ifndef UNTITLED_BATTERYEXCEPTION_H
#define UNTITLED_BATTERYEXCEPTION_H

#include <stdexcept>

class BatteryException : public std::logic_error {

public:
    BatteryException();
};


BatteryException::BatteryException()
: logic_error("Out of battery! Please, charge your Tesla.") {

}

#endif //UNTITLED_BATTERYEXCEPTION_H
