#include "priklad1.h"

/// Konstruktor, ktery zavola nacteni dat ze souboru a naplneni vektoru zaznamu
/// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska
/// na chybovy vystup - 2b
BallotList::BallotList(){
    std::string fileName = "/home/xkudla/Documents/Mendel/PCP/CV/PCPExam2/votes.txt";
    loadFile(fileName);
}

void BallotList::loadFile(const std::string fileName) throw (std::invalid_argument){
    std::ifstream in(fileName);
    if (in.is_open()){
        std::string tVotes;
        std::string sState;
        std::string tData;
        std::string sCandidate;
        while (in.eof()) {
            in >> tVotes >> sState >> tData >> sCandidate;
            insertBallot(sState, sCandidate, tData, tVotes);
        }
    }else{
        throw std::domain_error("soubor neotevren");
    }
    in.close();
}

/// metoda vlozi zaznam, provede transformaci pomoci labda vyrazu
/// ze stringu na dany typ vyctu - 6b
void BallotList::insertBallot(const std::string state, const std::string person,
                  const std::string date, const std::string counter){
    [state, person, date, counter](Ballot &bal){
        State tState;
        Candidate tCandidate;
        if (state == "Accepted") tState = State::Accepted;
        if (state == "Invalid") tState = State::Invalid;
        if (state == "Damaged") tState = State::Damaged;
        if (state == "Faked") tState = State::Faked;
        if (person == "DonaldTrump") tCandidate = Candidate::DonaldTrump;
        if (person == "JoeBiden") tCandidate = Candidate::JoeBiden;
        bal.state = tState;
        bal.person = tCandidate;
        bal.date = date;
    };

}

/// vraci pocty hlasu daneho typu pro jednotlive kandidaty. Tj. vyberu napr. ze chci neplatne listky a vrati se map
/// se dvema zaznamy: neplatne pro Trumpa a neplatne pro Bidena - 6b
std::map<Candidate, long> BallotList::getBallotsCount(const State state){
    std::map<Candidate, long> tru
    throw std::exception();
}

/// metoda vraci listky daneho typu: platne, neplatne...
/// pokud zaznam neni zadny zaznam nalezen, je vyhozena vyjimka - 6b
std::vector<Ballot> BallotList::getBallots(const State state) throw (std::invalid_argument){
    throw std::exception();
}