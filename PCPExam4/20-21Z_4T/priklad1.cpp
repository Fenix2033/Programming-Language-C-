#include "priklad1.h"

/// Konstruktor, ktery zavola nacteni dat ze souboru (viz metoda nize) a naplneni vektoru zaznamu
/// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska na chybovy vystup - 2b
BallotList::BallotList(){
    throw std::exception();
}

/// metoda nacitajici vsechny zaznamy ze souboru, uklada pomoci metody nize - 5b
/// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
void BallotList::loadFile(const std::string fileName) throw (std::invalid_argument){
    throw std::exception();
}

/// metoda vlozi zaznam - 6b
void BallotList::insertMeasuremnt(const std::string place, const std::string date,
                                  const float temperature, const int pressure){
    throw std::exception();
}
/// vraci map zaznamu, klicem je vzdy jmeno mista a hodnota je zaznam o mereni
/// s nejvyssi teplotou pro dane misto - 6b
std::map<std::string, StationMeasurent> BallotList::getHighestTemperatures(){
    throw std::exception();
}

/// vraci zaznamy z daneho mista, ktere maji minimalne dany tlak - 6b
std::vector<StationMeasurent> BallotList::getBallotsFromPlace(const std::string place, const int minimalPressure){
    throw std::exception();
}