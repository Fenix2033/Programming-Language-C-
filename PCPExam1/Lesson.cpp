//
//  Document.cpp
//  cpp
//
//  Created by Ivo Pisarovic on 15/01/2020.
//  Copyright © 2020 David. All rights reserved.
//

#include "Lesson.hpp"

// 6 bodu
/// Overte validitu vsech argumentu:
/// Parametr id musi byt vetsi rovno nule.
/// Parametr name overte pomoci regularu: musi byt neprazdny, musi obsahovat pouze pismena a cislice, nesmi zacinat cislici.
/// Parametr content musi byt neprazdny.
/// Parametr duration musi byt vetsi jak nula.
/// Pokud cokoliv nesedi, vyhodte vhodnou vyjimku.

Lesson::Lesson(long id, std::string name, std::string content, long duration){

    std::regex regular("^[a-zA-Z][0-9a-zA-Z]*$");

    if (id >= 0 and name != "" and content != "" and duration > 0){
        assert(id >= 0);
        assert(name != "");
        assert(content != "");
        assert(duration > 0);
        this->id = id;
        this->name = name;
        this->content = content;
        this->duration = duration;
    } else {
        throw std::invalid_argument("Not valid argument");
    }
}

long Lesson::getId() const{

    return this->id;
}

std::string Lesson::getName() const{

    return this->name;
}

std::string Lesson::getContent() const{

    return this->content;
}

long Lesson::getDuration() const{

    return this->duration;
}

int Lesson::getCountParticipants() const{
    return participants.size();
}

std::vector<Participant> Lesson::getParticipant() const{
    return participants;
}

void Lesson::addParticipants(Participant participant){
    participants.push_back(participant);
}

int Lesson::getCountMale() const{
    int male = 0;

    auto countMale = std::for_each(participants.begin(), participants.end(),
                                   [&male](const Participant &par)->void{
                                       auto gende = Gender::male;
                                       if (gende == par.gender) male++;
    });

    return male;
}

int Lesson::getCountFemale() const{
    int female = 0;
    auto countMale = std::for_each(participants.begin(), participants.end(),
                                   [&female](const Participant &par)->void{
                                       auto gende = Gender::female;
                                       if (gende == par.gender) female++;
                                   });

    return female;
}