//
//  Document.hpp
//  cpp
//
//  Created by Ivo Pisarovic on 15/01/2020.
//  Copyright © 2020 David. All rights reserved.
//

#ifndef Document_hpp
#define Document_hpp
#include <string>
#include <vector>
#include <stdexcept>
#include <regex>
#include <iostream>
#include <cassert>
#include "Participant.h"

/// 6 bodu
class Lesson {
private:
    long id;
    std::string name;
    std::string content;

    /// Duration of the lesson in seconds.
    long duration;

    std::vector<Participant> participants;

public:
    // 6 bodu
    /// Overte validitu vsech argumentu:
    /// Parametr id musi byt vetsi rovno nule.
    /// Parametr name overte pomoci regularu: musi byt neprazdny, musi obsahovat pouze pismena a cislice, nesmi zacinat cislici.
    /// Parametr content musi byt neprazdny.
    /// Parametr duration musi byt vetsi jak nula.
    /// Pokud cokoliv nesedi, vyhodte vhodnou vyjimku.
    Lesson(long id, std::string name, std::string content, long duration);

    long getId() const;
    std::string getName() const;
    std::string getContent() const;
    long getDuration() const;
    void addParticipants(Participant participant);

    int getCountParticipants() const;
    std::vector<Participant> getParticipant() const;
    int getCountMale() const;
    int getCountFemale() const;
};

#endif /* Document_hpp */
