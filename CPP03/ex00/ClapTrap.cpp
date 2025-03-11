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

void ClapTrap::takeDamage(unsigned int  amount)
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
        if (HitPoints > amount)
            HitPoints -= amount;
        else
            HitPoints = 0;
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
    if (HitPoints + amount >= amount)
        HitPoints += amount;
    else
        HitPoints = 4294967295;
    EnergyPoints--;
    std::cout << "ClapTrap " << name << " repairs itself and gains " << amount << " HP!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
    return (name);
}
unsigned int ClapTrap::getHP(void) const
{
    return (HitPoints);
}
unsigned int ClapTrap::getEP(void) const
{
    return (EnergyPoints);
}
unsigned int ClapTrap::getAD(void) const
{
    return (AttackDamage);
}
void ClapTrap::setHP(unsigned int Hp)
{
    HitPoints = Hp;
}
void ClapTrap::setEP(unsigned int Ep)
{
    EnergyPoints = Ep;
}
void ClapTrap::setAD(unsigned int Ad)
{
   AttackDamage = Ad;
}
void ClapTrap::setName(std::string new_name)
{
    name = new_name;
}

