#include "priklad1.h"

/// Konstruktor, ktery zavola nacteni dat ze souboru a naplneni vektoru zaznamu
/// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska
/// na chybovy vystup - 2b
BallotList::BallotList(){
    std::string fileName = "votes.txt";
    loadFile(fileName);
}

/// metoda nacitajici vsechny zaznamy ze souboru - 5b
/// pozor: jmeno ma vice slov
/// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
void BallotList::loadFile(const std::string fileName) throw (std::invalid_argument){
    std::ifstream read(fileName);
    if (read.is_open()){
        std::string sState;
        std::string sDate;
        std::string sPerson;
        std::string sRegion;

        while (!read.eof()){
            std::getline(read, sState, ',');
            read.ignore();
            std::getline(read, sDate, ',');
            read.ignore();
            std::getline(read, sPerson, ',');
            read.ignore();
            std::getline(read, sRegion);
            insertBallot (sState, sPerson, sDate, sRegion);
        }
    } else {
        throw std::domain_error("file is not open");
    }

    read.close();
}

/// metoda vlozi zaznam, provede transformaci pomoci labda vyrazu
/// ze stringu na dany typ vyctu - 6b
void BallotList::insertBallot(const std::string state, const std::string person,
                              const std::string date, const std::string region){

        auto helpBal = [state, person, date, region]()->Ballot{
        State tState;
        Candidate tPerson;
        Ballot bal;
        if (state == "Accepted") tState = State::Accepted;
        else if (state == "Invalid") tState = State::Invalid;
        else if (state == "Damaged") tState = State::Damaged;
        else if (state == "Faked") tState = State::Faked;
        if (person == "Babis") tPerson = Candidate::Babis;
        else if (person == "Nemcova") tPerson = Candidate::Nemcova;
        else if (person == "Nerodova") tPerson = Candidate::Nerudova;
        else if (person == "Pavel") tPerson = Candidate::Pavel;
        bal = {tState, tPerson, date, region};
        return bal;
    };

    m_ballots.push_back(helpBal());

}

/// vraci vysledkovou listinu, tj. vzdy dotycneho kandidata a pocet PLATNYCH hlasu pro daneho kandidata ze cele CR- 6b
std::map<Candidate, long> BallotList::getBallotsCount(){
    std::map<Candidate, long> acceptedList;
    long countBabis = 0;
    long countNemcova = 0;
    long countNerodova = 0;
    long countPavel = 0;

    try { std::for_each(m_ballots.begin(), m_ballots.end(),
                        [&countBabis, &countNemcova, &countNerodova, &countPavel](const Ballot &bal)->void{
        if (bal.state == State::Accepted ){
            if (bal.person == Candidate::Babis) countBabis++;
            else if (bal.person == Candidate::Nemcova) countNemcova++;
            else if (bal.person == Candidate::Nerudova) countNerodova++;
            else if (bal.person == Candidate::Pavel) countPavel++;
        }

    });
    } catch (std::invalid_argument) {
        throw std::exception();
    }

    acceptedList[Candidate::Babis] = countBabis;
    acceptedList[Candidate::Nemcova] = countNemcova;
    acceptedList[Candidate::Nerudova] = countNerodova;
    acceptedList[Candidate::Pavel] = countPavel;

    return acceptedList;
}

/// metoda vraci listky daneho typu pro dany region
/// pokud zaznam neni zadny zaznam nalezen, je vyhozena vyjimka - 6b
std::vector<Ballot> BallotList::getBallots(const State state, const std::string region) throw (std::invalid_argument){
    std::vector<Ballot> listRegion;
    try {
        std::for_each(m_ballots.begin(), m_ballots.end(),
                      [&listRegion, state, region](const Ballot &bal)->void{
            if (bal.state == state and bal.region == region){
                listRegion.push_back(bal);
            }
        });

    } catch (std::invalid_argument) {
        throw std::exception();
    }


    return listRegion;
}
