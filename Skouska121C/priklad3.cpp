#include "priklad3.h"
SkladovyList::SkladovyList(int invCislo){
    m_inventarniCislo=invCislo;
}

int SkladovyList::getInventarniCislo(){
    return m_inventarniCislo;
}

void SkladovyList::setInventarniCislo(int noveInvCislo){
    m_inventarniCislo=noveInvCislo;
}

Zbozi::Zbozi(std::string popis, int inventarniCislo){
    m_popis=popis;
    m_list=new SkladovyList(inventarniCislo);
}

Zbozi::Zbozi(const Zbozi& vzor){
    m_popis=vzor.m_popis;
    m_list=new SkladovyList(vzor.m_list->getInventarniCislo());
}

std::string Zbozi::getPopis(){
    return m_popis;
}
int Zbozi::getInventarniCislo(){
    return m_list->getInventarniCislo();
}

void Zbozi::setInventarniCislo(int noveInvCislo){
    m_list->setInventarniCislo(noveInvCislo);
}

Zbozi::~Zbozi(){
    delete m_list;
}
