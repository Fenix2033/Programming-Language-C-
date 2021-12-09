#ifndef __cpp_test1__priklad2__
#define __cpp_test1__priklad2__

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

// 15 b

/// Trida zbran
class Weapon{
private:
    /// jmeno zbrane
    std::string m_name;
    /// sila zbrane
    float m_strength;
public:
    Weapon(const std::string name, const float strength){
        m_name = name;
        m_strength = strength;
    }
    std::string getName() const{
        return m_name;
    }
    
    float getStrength() const{
        return m_strength;
    }
};

/// Trida reprezentujici hrdinu.
class Hero {
protected:
    /// jmeno vyrobce
    std::string m_name;
    /// zbrane: pomoci inteligentnich ukazatelu vyreste, aby se hrdinovi mohl predat mec nebo jina zbran do seznamu
    /// tuto zbran musi vlastni vyhradne hrdina, pokud si ji k sobe ulozi. Nesmi existovat situace, ze ukazatel na
    /// zbran ma jak hrdina, tak "nekdo" kdo ji hrdinovi predal - spravna definicie atributu (3 body)
    // ??? m_weapons;

public:
    /// Konstruktor vytvarejici hrdinu. (1 bod)
    Hero(const std::string name);

    /// Destruktor smaze zbran vlastnenou hrdinou (3 body)
    ~Hero();

private:
    /// Pridani zbrane do seznamu zbrani  (4 body)
    //void addWeapon(???);

    /// Vypise jmena zbrani na obrazovku (4 body)
    void printWeapons();
};


#endif /* defined(__cpp_test1__priklad2__) */
