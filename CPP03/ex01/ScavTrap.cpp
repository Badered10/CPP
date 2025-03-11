#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap named " << this->name << " has been called for duty!" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("Unnamed", 100, 50, 20)
{
    std::cout << "A random ScavTrap has been called for duty!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    *this = obj;
    std::cout << "Kage Bunshin no Jutsu!!! ScavTrap clone named " << " has been called for duty!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap named " << " has died with honor. RIP!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        this->HitPoints = obj.HitPoints;
        this->EnergyPoints =  obj.EnergyPoints;
        this->AttackDamage =  obj.AttackDamage;
    }
    return (*this);
}