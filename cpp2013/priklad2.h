#ifndef cpp2011z_priklad2_h
#define cpp2011z_priklad2_h

#include <iostream>
#include <sstream>

namespace Store {
    
    /// CELKEM 22
    class Decoder{
    public:
        /// Kazdy carovy kod musi mit delku 13 znaku: ABC23123123123X
        /// prvni tri znaky musi byt velka pismena, nasleduje cislo
        /// ktere musi byt delitelne tremi. Na konci je opet pismeno.
        /// Provedte kontrolu, zda ma predane cislo pozadovanou strukturu. (6 bodu)
        bool hasCorrectStructure(const std::string code);
        /// Metode je predano slovo formatu AA1B2, A222X4, X24A3 atp.
        /// Tj. vzdy libovolny pocet znaku, libovolny pocet cislic, znaky, cislice
        /// Rozdelte kod na jeho casti a ty vratte pomoci prislusnych parametru
        /// Pro rozdeleni na jednotlive casti pouzijte regularni vyraz.
        /// Pokud kod nema pozadovanou strukturu, vyhodi se vyjimka (6 bodu)
        void decodePosition(const std::string word, char &rowLetter, int &rowPosition,
                            char &columnLetter, int &columnNumber) throw (std::exception);
        /// Metoda dostane v parametrech den, mesic a rok. Dale dostane string ve formatu YYYYMMDDXXX
        /// Kde XXX je sekvence cisel, ktery s datem nesouvisi.
        /// Rozhodnete, zda jsou si data rovny (3 bodu)
        bool isDateEqual(const int day, const int month, const int year, const std::string date);
    };
    
    /// Napiste test na tridu podle nachystane kostry (7 bodu)
}
#endif
