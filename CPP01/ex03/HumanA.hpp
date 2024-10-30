#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
    Weapon      equipment;
    std::string name;
public:
    HumanA(std::string, Weapon);
    ~HumanA();
    void attack(void);
};




#endif