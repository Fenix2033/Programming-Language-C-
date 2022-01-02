//
//  Document.cpp
//  cpp
//
//  Created by Ivo Pisarovic on 15/01/2020.
//  Copyright © 2020 David. All rights reserved.
//

#include "Guest.hpp"

// 6 bodu
/// Konstruktor navstevnika ski arealu.
/// Overte validitu vstupnich argumentu - 1b
/// Pokud cokoliv nesedi, vyhodte vhodnou vyjimku - 1b
/// - Parametr id musi byt vetsi rovno 0.
/// - Parametr name musi byt neprazdne.
/// - Parametr vek musi byt vetsi nez 0.
/// Dale podle veku rozhodnete, zda ma navstevnik slevu - 1b
/// Dale pomoci jednoho regularniho vyrazu zjistete, zda lekarska zprava obsahuje pozitivni nalez nemoci COVID-19 - 3b
/// Pozor, zprava muze obsahovat ruznou velikost pismen a vyjadreni teto informace.
/// Zajistete odchyceni nasledujicich formatu:
/// covid19, covid2019, covid 19, covid 2019 ... a to same s ruznou velikosti pismen
Guest::Guest(long id, std::string name, int age, std::string doctorsMessage){

            if (id >= 0 and name != "" and age > 0){

                assert(id >= 0);
                assert(name != "");
                assert(age > 0);
                std::regex regular("^[a-zA-Z][0-9a-zA-Z]*$");
                if (age < 18) this->hasChildDiscount = true;
                else this->hasChildDiscount = false;
                if (doctorsMessage != "" and std::regex_match(name, regular)) this->hasCovid = true;
                else this->hasCovid = false;
                this->id = id;
                this->name = name;

            } else {
                throw std::invalid_argument("Not valid argument");
            }
}

bool Guest::getCovid() const {
    return hasCovid;
}

bool Guest::getSell() const{
    return hasChildDiscount;
}

std::string Guest::getName() const{
    return name;
}