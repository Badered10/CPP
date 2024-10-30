#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
}

void HumanB::attack(void)
{
    std::cout << name << " attacks with their " 
            << equipment.getType() << std::endl;
}

void HumanB::setWeapon(Weapon equipment)
{
    this->equipment = equipment;
}
