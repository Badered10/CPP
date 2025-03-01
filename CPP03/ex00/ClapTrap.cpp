#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) 
{
    std::cout << "ClapTrap named " << name << " has been called for duty!" << std::endl;
}

ClapTrap::ClapTrap() : name("Unnamed"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "A random ClapTrap has been called for duty!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    *this = obj;
    std::cout << "Kage Bunshin no Jutsu!!! ClapTrap clone named " << name << " has been called for duty!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap named " << name << " has died with honor. RIP!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
    {
        name = obj.name;
        HitPoints = obj.HitPoints;
        EnergyPoints = obj.EnergyPoints;
        AttackDamage = obj.AttackDamage;   
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because he has already died on the field!" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack because he's completely drained!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
    EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed and cannot take more damage!" << std::endl;
        return;
    }

    if (amount >= HitPoints)
    {
        HitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage and is destroyed!" << std::endl;
    }
    else
    {
        HitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " damage and now has " << HitPoints << " HP left!" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired because he has already died on the field!" << std::endl;
        return;
    }
    if (EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot be repaired because he's completely drained!" << std::endl;
        return;
    }

    unsigned int res = amount;
    if (HitPoints + amount > 10)
        res = 10 - HitPoints;

    HitPoints += res;
    EnergyPoints--;

    std::cout << "ClapTrap " << name << " repairs itself and gains " << res << " HP!" << std::endl;
}
