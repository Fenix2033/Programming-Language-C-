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
    long tmpId = id;
    if (id < 0) tmpId = 0;
    assert(tmpId >= 0);

    std::regex regular("^[a-z][0-9a-z]*$");
    std::string tmpName = name;
    if (!regex_match(name, regular) and name == "") tmpName = "A";
    assert(tmpName != "");

    std::string tmpContent = content;
    if (!regex_match(name, regular) and name == "") tmpContent = "A";
    assert(tmpContent != "");

    long tmpDuration = duration;
    if (duration <= 0) tmpDuration = 1;
    assert(tmpDuration > 0);

    this->id = tmpId;
    this->name = tmpName;
    this->content = tmpContent;
    this->duration = tmpDuration;
}

long Lesson::getId() const{
    assert(this->id >= 0);
    return this->id;
}

std::string Lesson::getName() const{
    assert(this->name != "");
    return this->name;
}

std::string Lesson::getContent() const{
    assert(this->content != "");
    return this->content;
}

long Lesson::getDuration() const{
    assert(this->duration > 0);
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