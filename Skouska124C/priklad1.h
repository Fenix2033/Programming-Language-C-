#ifndef cpp2011z_priklad1_h
#define cpp2011z_priklad1_h

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <map>
// CELKEM 30 b
/// Trida reprezentujici bezpecnostni udalost v bezpecnostnim informacnim systemu - 1 b
class Event{
public:
    std::string m_area;             /// oblast kde nastala bezpecnosti udalost (kod, napr. Q237)
    std::string m_typeOfProblem;    /// typ problemu (pohyb, zvuk, ...)
    float m_length;                 /// delka udalosti (23.5 s)

    Event(std::string area, std::string typeOfProblem, float length);
};


class BezpecnostniIS{
private:
    /// struktura ukladajici bezpecnostni udalosti
    /// klic je casove razitko (20111230), hodnota je zaznam udalosti
    std::multimap<long, Event> m_events;

public:
    /// nahraje ulozene udalosti ze skouboru,
    /// pokud je zadano spatne jmeno, vyhodi vyjimku - 9 bodu
    void loadImageFromTextFile(std::string fileName) throw (std::domain_error);
    /// vrati pocet bezpecnostnich zaznamu, ktere odpovidaji danemu typu (typeOfProblem) - 5 b
    int getNumberOfEvents(std::string typeOfProblem);
    /// vymaze veskere bezpecnostni udalosti pred zvolenym datumem - 5 b
    void eraseBefore(long timeStamp);
    /// vypise casova razitka veskerych udalosti zvoleneho typu - 5 b
    void printEvents(std::string typeOfProblem);
    /// vrati casove razitko posledni udalosti ve zvolene lokaci,
    /// 0 pokud zaznam z lokace neni - 5 b
    long findLastEventinArea(std::string area);
};

#endif
