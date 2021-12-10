#ifndef cpp2011z_priklad3_h
#define cpp2011z_priklad3_h

#include <iostream>

/// Trida pro ukladani informaci o objektu, metody zrejme
class SkladovyList{
private:
    int m_inventarniCislo;
public:
    SkladovyList(int invCislo);
    int getInventarniCislo();
    void setInventarniCislo(int noveInvCislo);
};


class Zbozi{
private:
    std::string m_popis;
    SkladovyList* m_list;
public:
    /// Konstruktor, ktery naplni popis a pomoci kompozice vytvori skladovy list
    Zbozi(std::string popis, int inventarniCislo);
    /// Kopirovaci konstruktor, ktery zajisti korekni kopii objektu
    Zbozi(const Zbozi& vzor);
    // dale jsou klasicke metody pro pristup k atributum
    std::string getPopis();
    int getInventarniCislo();
    void setInventarniCislo(int noveInvCislo);
    /// Dest. pro korektni uvolneni pameti
    ~Zbozi();
};

#endif
