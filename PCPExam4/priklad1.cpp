#include "priklad1.h"

/// Konstruktor, ktery zavola nacteni dat ze souboru (viz metoda nize) a naplneni vektoru zaznamu
/// pokud je pri nacteni vyhozena vyjimka, je zpracovana a je vypsaha hlaska na chybovy vystup - 2b
BallotList::BallotList(){
    try {
        std::string fileName = "measurements.txt";
        loadFile(fileName);
    } catch (std::invalid_argument){
        throw std::exception();
    }
}

/// metoda nacitajici vsechny zaznamy ze souboru, uklada pomoci metody nize - 5b
/// v pripade, ze soubor neexistuje je vyhozena vyjimka, pouzije vkladaci metodu nize
void BallotList::loadFile(const std::string fileName) throw (std::invalid_argument){

    std::ifstream read(fileName);
    if (read.is_open()){
        std::string place;
        std::string date;
        std::string sTemperature;
        std::string sPressure;
        float temperature;
        int pressure;

        while (!read.eof()){
            read >> place >> date >> sTemperature >> sPressure;
            temperature = std::stof(sTemperature);
            pressure = std::stoi(sPressure);
            insertMeasuremnt(place, date, temperature, pressure);
        }

    } else {
        throw std::exception();
    }

    read.close();

}

/// metoda vlozi zaznam - 6b
void BallotList::insertMeasuremnt(const std::string place, const std::string date,
                                  const float temperature, const int pressure) {
    try {
        auto helpStation = [place, date, temperature, pressure] {
            StationMeasurent sta;
            sta = {place, temperature, pressure, date};
            return sta;
        };

        m_measurements.push_back(helpStation());

    } catch (std::invalid_argument){
        throw std::exception();
    }
}

/// vraci map zaznamu, klicem je vzdy jmeno mista a hodnota je zaznam o mereni
/// s nejvyssi teplotou pro dane misto - 6b
std::map<std::string, StationMeasurent> BallotList::getHighestTemperatures(){
    std::map<std::string, StationMeasurent> measur;
    StationMeasurent brno;
    StationMeasurent prague;
    StationMeasurent ostrava;

    try { std::for_each(m_measurements.begin(), m_measurements.end(),
                        [&brno, &prague, &ostrava](const StationMeasurent& sta){
                            if (sta.place == "BRNO"){
                                if (sta.temperature > brno.temperature) brno = sta;
                            }
                            else if (sta.place == "PRAGUE") {
                                if (sta.temperature > prague.temperature) prague = sta;
                            }
                            else if (sta.place == "OSTRAVA") {
                                if (sta.temperature > ostrava.temperature) ostrava = sta;
                            }
                        });
        measur["BRNO"] = brno;
        measur["PRAGUE"] = prague;
        measur["OSTRAVA"] = ostrava;

        return measur;

    } catch (std::invalid_argument){
        throw std::exception();
    }
}

/// vraci zaznamy z daneho mista, ktere maji minimalne dany tlak - 6b
std::vector<StationMeasurent> BallotList::getBallotsFromPlace(const std::string place, const int minimalPressure){
    std::vector<StationMeasurent> measur;

    try { std::for_each(m_measurements.begin(), m_measurements.end(),
                        [place, minimalPressure, &measur](const StationMeasurent& sta){
                            if (sta.place == place) {
                                if (sta.pressure == minimalPressure){
                                    measur.push_back(sta);
                                }
                            }

                        });

        return measur;

    } catch (std::invalid_argument){
        throw std::exception();
    }
}