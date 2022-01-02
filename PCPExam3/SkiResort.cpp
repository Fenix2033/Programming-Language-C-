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
    std::ofstream file("ticket.txt");
    if (file.is_open()) {
        file << "Jmeno " << guest.getName();
        if (guest.getCovid() == true) file << "*";
        file << std::endl;
        if (guest.getSell() == true) {
            file << "C" << std::endl;
            file << "Cena: 350 Kc";
        } else {
            file << "A" << std::endl;
            file << "Cena: 750 Kc";
        }

        file.close();
    } else {
        std::cerr << "File is not open" << std::endl;
    }
}

// 4 body
/// Vratte kolik procent navstevniku ma COVID.
float SkiResort::getRatioOfCovidPositiveGuests() const{

    int hasCovid = 0;
    int notHasCovid = 0;

    std::for_each(m_guests.begin(), m_guests.end(),
                                    [&hasCovid, &notHasCovid](const Guest& gues)->void{
        if (gues.getCovid() == true) hasCovid++;
        else notHasCovid++;
    });

    if (hasCovid == 0) return 0.0;
    if (notHasCovid == 0) return 100.0;

    return 100/(hasCovid + notHasCovid) * hasCovid;
}

// 5 body
/// Vrati vsechny navstevniky serazene podle abecedy od konce.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Guest> SkiResort::getSortedGuests() const{
    std::vector<Guest> guests;
    guests = m_guests;

    std::sort(guests.begin(), guests.end(),
         [](const Guest& g1, const Guest& g2) -> bool{
        return g1.getName() > g2.getName();
    });

    return guests;
}

// 6 bodu
/// Spočítejte počet dětí.
/// Pouzijte STL algoritmus a lambda vyraz.
long SkiResort::getCountOfChildren() const{
    long pocetDeti = std::count_if(m_guests.begin(), m_guests.end(),
                  [](const Guest &gue) -> bool{
                      return gue.getSell() == true;
    });

    return pocetDeti;
}

/// 8 bodu
/// Vratte vsechny navstevniky, jejich jmeno zacina pismenem predanym jako parametr.
/// Pouzije STL algoritmus a lambda vyraz.
std::vector<Guest> SkiResort::getGuestsStartingWith(char firstLetter) const {
    std::vector<Guest> guests;

    auto foundGuest = m_guests.begin();

    while (foundGuest != m_guests.end()){

        foundGuest = std::find_if(foundGuest, m_guests.end(),
                                       [firstLetter, &foundGuest](const Guest &gue) {

                                           return gue.getName().at(0) == firstLetter;
                                       });

        if (foundGuest != m_guests.end()) {
            guests.push_back(*foundGuest);

        }

        foundGuest++;
    }

        return guests;
}
