#include <memory>
#include "priklad2.h"

/// Konstruktor (2 body)
Hero::Hero(const std::string name){
    m_name = name;
}

/// Destruktor (3 body)
Hero::~Hero(){

    m_weapons.erase(m_weapons.begin(), m_weapons.end());

}

/// Pridani zbrane do seznamu zbrani  (4 bodu)
void Hero::addWeapon(Weapon weapon){
    Weapon wep = std::move(weapon);
    m_weapons.push_back(wep);
}

/// Smaze zbran s danym jmenem v seznamu (3 body)
void Hero::destroyWeapon(std::string weaponName) {

    for (int i = 0; i < m_weapons.size(); i++) {
        if (m_weapons.at(i).getName() == weaponName) {
            std::vector<Weapon>::iterator actWeapon = m_weapons.begin() + i;
            m_weapons.erase(actWeapon);
        };
    }
}
