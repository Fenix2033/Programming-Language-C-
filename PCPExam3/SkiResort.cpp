#include "SkiResort.hpp"

/// 1 bod
/// Novy navstevnik prijel do ski arealu. Zaregistrujte ho.
void SkiResort::addGuest(Guest guest){
    m_guests.push_back(guest);
}

/// 4 body
/// Vytisknete zakaznikovi jizdenku.
/// Jizdenku vytisknete do textoveho souboru.
/// Format:
/// Jmeno * (hvezdicku vypiste jen tehdy, pokud ma navstevnik covid)
/// A/C (A pokud je to dospely, C pokud ma detskou slevu)
/// Cena XX Kc (kde XX je 750Kc pro dospeleho a 350 Kc pro dite)
/// Dbejte na spravne otevreni a uzavreni souboru.
void SkiResort::printTicket(Guest guest){

}

// 4 body
/// Vratte kolik procent navstevniku ma COVID.
float SkiResort::getRatioOfCovidPositiveGuests() const{

}

// 5 body
/// Vrati vsechny navstevniky serazene podle abecedy od konce.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Guest> SkiResort::getSortedGuests() const{

}

// 6 bodu
/// Spočítejte počet dětí.
/// Pouzijte STL algoritmus a lambda vyraz.
long SkiResort::getCountOfChildren() const{

}

/// 8 bodu
/// Vratte vsechny navstevniky, jejich jmeno zacina pismenem predanym jako parametr.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Guest> SkiResort::getGuestsStartingWith(char firstLetter) const{

}