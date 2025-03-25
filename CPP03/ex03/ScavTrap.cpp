#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    this->EnergyPoints = 50;
    // this->AttackDamage = 20;
    std::cout << "ScavTrap named " << this->name << " has been called for duty!" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("Unnamed", 100, 50, 20)
{
    std::cout << "A random ScavTrap has been called for duty!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    *this = obj;
    std::cout << "Kage Bunshin no Jutsu!!! ScavTrap clone named " << " has been called for duty!" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap named " << name << " has died with honor. RIP!" << std::endl;
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

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap named " << name << " actvite guardGate !!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (HitPoints == 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack because he has already died on the field!" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ScavTrap " << name << " cannot attack because he's completely drained!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    EnergyPoints--;
}