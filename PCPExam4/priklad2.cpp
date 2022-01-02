#include "priklad2.h"

Hero::Hero(const std::string name){
    m_name = name;
}

/// Destruktor (3 body)
Hero::~Hero(){
    m_weapons.erase(m_weapons.begin(), m_weapons.end());
}

/// Pridani zbrane do seznamu zbrani (4 bodu)
void Hero::addWeapon(Weapon weapon){
    Weapon wep = std::move(weapon);
    m_weapons.push_back(wep);
}

/// Vypise jmena zbrani na obrazovku (3 body)
void Hero::printWeapons(){
    for (int i = 0; i < m_weapons.size(); i++){
        std::cout << m_weapons.at(i).getName() << std::endl;
    }
}