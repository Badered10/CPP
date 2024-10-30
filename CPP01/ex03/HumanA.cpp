#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name , Weapon equipment)
{
    this->name = name;
    this->equipment = equipment;
}

HumanA::~HumanA()
{
}

void HumanA::attack(void)
{
    std::cout << name << " attacks with their " 
            << equipment.getType() << std::endl;
}
