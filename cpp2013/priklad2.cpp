#include "priklad2.h"


/// Kazdy carovy kod musi mit delku 13 znaku: ABC23123123123X
/// prvni tri znaky musi byt velka pismena, nasleduje cislo
/// ktere musi byt delitelne tremi. Na konci je opet pismeno.
/// Provedte kontrolu, zda ma predane cislo pozadovanou strukturu. (7 bodu)
bool Store::Decoder::hasCorrectStructure(const std::string code)
{
    return true;
}

/// Metode je predano slovo formatu AA1B2, A222X4, X24A3 atp.
/// Tj. vzdy libovolny pocet znaku, libovolny pocet cislic, znaky, cislice
/// Rozdelte kod na jeho casti a ty vratte pomoci prislusnych parametru
/// Pro rozdeleni na jednotlive casti pouzijte regularni vyraz.
/// Pokud kod nema pozadovanou strukturu, vyhodi se vyjimka
void Store::Decoder::decodePosition(const std::string code, char &rowLetter, int &rowPosition, 
                                    char &columnLetter, int &columnNumber) throw (std::exception)
{

}

/// Metoda dostane v parametrech den, mesic a rok. Dale dostane string ve formatu YYYYMMDDXXX
/// Kde XXX je sekvence cisel, ktery s datem nesouvisi.
/// Rozhodnete, zda jsou si data rovny (5 bodu)
bool Store::Decoder::isDateEqual(const int day, const int month, const int year, const std::string date)
{
    return true;
}