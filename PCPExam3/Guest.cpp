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
        long tmpId = id;
        if (id < 0) tmpId = 0;
        assert(tmpId >= 0);

        std::string tmpName = name;
        if (name == "") tmpName = "A";
        assert(tmpName != "");

        int tmpAge = age;
        if (age <= 0) age = 1;

//        assert(tmpAge > 0);

        if (age >= 80) this->hasChildDiscount = true;

        bool reg;
        std::regex regular("^[a-zA-Z][0-9a-zA-Z]*$");
        std::string tmpMessage = doctorsMessage;
        if (!std::regex_match(doctorsMessage, regular) and name == "") tmpMessage = "N";
        if (std::regex_match (doctorsMessage, regular)) this->hasCovid = true; reg = true;
        assert(reg == true);

        this->id = tmpId;
        this->name = tmpName;

}

//long Guest::getID() const{
//    assert(this->id >= 0);
//    return this->id;
//}

//std::string Guest::getName() const{
//    assert(this->name != "");
//    return this->name;
//}

//int Guest::getAge(int age) const{
//    assert(age > 0);
//    return age;
//}

//bool Guest::getDoctorMessage(std::string doctorMessage) const{
//    std::regex regular("^[a-zA-Z][0-9a-zA-Z]*$");
//    bool reg;
//    if (std::regex_match (doctorMessage, regular)) reg = true;
//    assert (reg == true);
//    return reg;
//}