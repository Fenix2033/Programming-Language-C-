#ifndef PRIKLAD1_H
#define PRIKLAD1_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <algorithm>

/*
 25 b
*/

/// vyctovy typ uchovavajici stav volebniho listku
enum class State {Accepted, Invalid, Damaged, Faked};
/// volena osoba
enum class Candidate {Nerudova, Babis, Pavel, Nemcova};

/// struktura uchovavajici popis jednoho volebniho listku
struct Ballot{
    State state;        // stav listku
    Candidate person;   // volena osoba
    std::string date;   // datum podani listku ve formatu yyyymmddhhmm
    std::string region;  // kraj odkud je hlas
};

/// Trida reprezentujici evidenci volebnich listku.
/// Pri implementaci metod pouzivejte v maximalni mozne mire algoritmy STL a lambda vyrazu!!!
class BallotList{
private:
    /// vektor vsech volebnich listku
    std::vector<Ballot> m_ballots;
public:
    /// Konstruktor, ktery zavola nacteni dat ze souboru a naplneni vektoru zaznamu
    /// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska
    /// na chybovy vystup - 2b
    BallotList();
    /// metoda nacitajici vsechny zaznamy ze souboru - 5b
    /// pozor: jmeno ma vice slov
    /// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
    void loadFile(const std::string fileName) throw (std::invalid_argument);
    /// metoda vlozi zaznam, provede transformaci pomoci labda vyrazu
    /// ze stringu na dany typ vyctu - 6b
    void insertBallot(const std::string state, const std::string person,
                      const std::string date, const std::string region);
    /// vraci vysledkovou listinu, tj. vzdy dotycneho kandidata a pocet PLATNYCH hlasu pro daneho kandidata ze cele CR- 6b
    std::map<Candidate, long> getBallotsCount();
    /// metoda vraci listky daneho typu pro dany region
    /// pokud zaznam neni zadny zaznam nalezen, je vyhozena vyjimka - 6b
    std::vector<Ballot> getBallots(const State state, const std::string region) throw (std::invalid_argument);
};

#endif // PRIKLAD1_H_INCLUDED
