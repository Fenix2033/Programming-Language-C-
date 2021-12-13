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
    /// zbrane: Pomoci inteligentnich ukazatelu vyreste, aby se hrdinovi mohl predat mec nebo jina zbran do seznamu zbrani.
    /// Zajistete, aby hrdina byl vylucnym vlastnikem dane zbrane, tj. nikdo jiny na ni nesmi mit platny ukazatel (3 body)
    std::vector<Weapon> m_weapons;

public:
    /// Konstruktor vytvarejici hrdinu. (2 body)
    Hero(const std::string name);

    /// Destruktor (3 body)
    ~Hero();

private:
    /// Pridani zbrane do seznamu zbrani  (5 bodu)
    void addWeapon(Weapon weapon);

    /// Smaze zbran s danym jmenem v seznamu (5 body)
    void destroyWeapon(std::string weaponName);
};


#endif /* defined(__cpp_test1__priklad2__) */
