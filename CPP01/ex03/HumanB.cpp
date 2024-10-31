#include "HumanB.hpp"
#include <cstddef>
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->equipment = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " ;

    if (!equipment)
        std::cout << "without weapon" << std::endl;
    else
        std::cout << this->equipment->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &equipment)
{
    this->equipment = &equipment;
}
