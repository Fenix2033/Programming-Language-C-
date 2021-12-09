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

/// struktura uchovavajici popis jednoho mereni
struct StationMeasurent{
    std::string place;  // misto mereni
    float temperature;  // teplota
    int pressure;       // atmosfericky tlak
    std::string date;   // datum ve formatu yyyymmdd
};

/// Trida reprezentujici evidenci mereni
/// Pri implementaci metod pouzivejte v maximalni mozne mire algoritmy STL a lambda vyrazu!!!
class BallotList{
private:
    /// seznam mereni na ruznych mistech
    std::vector<StationMeasurent> m_measurements;
public:
    /// Konstruktor, ktery zavola nacteni dat ze souboru (viz metoda nize) a naplneni vektoru zaznamu
    /// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska na chybovy vystup - 2b
    BallotList();
    /// metoda nacitajici vsechny zaznamy ze souboru, uklada pomoci metody nize - 5b
    /// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
    void loadFile(const std::string fileName) throw (std::invalid_argument);
    /// metoda vlozi zaznam - 6b
    void insertMeasuremnt(const std::string place, const std::string date,
                      const float temperature, const int pressure);
    /// vraci map zaznamu, klicem je vzdy jmeno mista a hodnota je zaznam o mereni
    /// s nejvyssi teplotou pro dane misto - 6b
    std::map<std::string, StationMeasurent> getHighestTemperatures();
    /// vraci zaznamy z daneho mista, ktere maji minimalne dany tlak - 6b
    std::vector<StationMeasurent> getBallotsFromPlace(const std::string place, const int minimalPressure);
};

#endif // PRIKLAD1_H_INCLUDED
