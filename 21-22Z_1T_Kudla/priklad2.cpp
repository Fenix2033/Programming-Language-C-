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
    std::vector<Weapon>::iterator it;
    for(it = m_weapons.begin(); it <= m_weapons.end(); it++){
        m_weapons.insert(it, weapon);
    }

}

/// Smaze zbran s danym jmenem v seznamu (3 body)
void Hero::destroyWeapon(std::string weaponName){
    std::vector<Weapon>::iterator it;
    for (it = m_weapons.begin(); it != m_weapons.end(); it++){
        if (it->getName() == weaponName){
            m_weapons.erase(it);
        }
    }
}
