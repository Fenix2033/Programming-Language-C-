#ifndef cpp2011z_priklad3_h
#define cpp2011z_priklad3_h

#include <vector>
#include <iostream>

// CELKEM 20 b
class Strings{
private:
    /// uklada jednotlive vety
    std::vector<std::string> m_sentences;
public:
    /// Konstruktor prevezme predany text a rozdeli jej po vetach do vectoru - 10 bodu
    /// Kazda veta konci teckou. Tj. Mama mele maso. Jan ma kolo. bude rozdeleno na dva zaznamy
    Strings(std::string input);
    /// vraci pocet vet - 3 body
    int getNumberOfSenteces();
    /// vrati nejdelsi vetu nebo prazdny retezec, pokud je vektor prazdny - 7 bodu
    std::string getLongestSentence();
};

#endif
