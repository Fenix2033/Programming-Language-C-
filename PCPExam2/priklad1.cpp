#include "priklad1.h"

/// Konstruktor, ktery zavola nacteni dat ze souboru a naplneni vektoru zaznamu
/// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska
/// na chybovy vystup - 2b
BallotList::BallotList(){
    std::string fileName = "/home/xkudla/Documents/Mendel/PCP/CV/PCPExam2/votes.txt";
    loadFile(fileName);
    std::map<std::string, Ballot>::iterator it;

}

void BallotList::loadFile(const std::string fileName) throw (std::invalid_argument){
    std::ifstream in(fileName);
    if (in.is_open()){
        std::string tVotes;
        std::string sState;
        std::string tData;
        std::string sPerson;
        State tState;
        Candidate tPerson;
        while (in >> tVotes >> sState >> tData >> sPerson) {

            insertBallot(sState, sPerson, tData, tVotes);
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

    auto helpBal = [state, person, date, counter]() -> Ballot{
        State tState;
        Candidate tCandidate;
        Ballot bal;
        if (state == "Accepted") tState = State::Accepted;
        else if (state == "Invalid") tState = State::Invalid;
        else if (state == "Damaged") tState = State::Damaged;
        else if (state == "Faked") tState = State::Faked;
        if (person == "DonaldTrump") tCandidate = Candidate::DonaldTrump;
        else if (person == "JoeBiden") tCandidate = Candidate::JoeBiden;
        bal = {tState, tCandidate, date};
        return bal;
    };


    m_orders.insert(std::pair<std::string, Ballot>(counter, helpBal()));

}

/// vraci pocty hlasu daneho typu pro jednotlive kandidaty. Tj. vyberu napr. ze chci neplatne listky a vrati se map
/// se dvema zaznamy: neplatne pro Trumpa a neplatne pro Bidena - 6b
std::map<Candidate, long> BallotList::getBallotsCount(const State state){
    std::map<Candidate, long> novyMap;
    long pocetBaiden = 0;
    long pocetTrump = 0;

    auto count = std::for_each(m_orders.begin(), m_orders.end(),
                  [state, &pocetBaiden, &pocetTrump](const std::pair<std::string, Ballot> &ord)->void{
                      if (state == ord.second.state and Candidate::DonaldTrump == ord.second.person) {
                          pocetTrump++;
                      }
                      else if (state == ord.second.state and Candidate::JoeBiden == ord.second.person){
                          pocetBaiden++;
                      }
                  });

    novyMap[Candidate::JoeBiden] = pocetBaiden;
    novyMap[Candidate::DonaldTrump] = pocetTrump;

    return novyMap;

}

/// metoda vraci listky daneho typu: platne, neplatne...
/// pokud zaznam neni zadny zaznam nalezen, je vyhozena vyjimka - 6b
std::vector<Ballot> BallotList::getBallots(const State state) throw (std::invalid_argument){
    std::vector<Ballot> listky;

    auto count = std::for_each(m_orders.begin(), m_orders.end(),
                               [state, &listky](const std::pair<std::string, Ballot> &ord)->void{
                                   if (state == ord.second.state){
                                       listky.push_back(ord.second);
                                   }});

    return listky;
    throw std::exception();
}
