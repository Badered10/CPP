#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
    Weapon      *equipment;
    std::string name;
public:
    HumanB(std::string);
    ~HumanB();
    void attack(void);
    void setWeapon(Weapon &equipment);
};




#endif