#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
    this->HitPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap named " << this->name << " has been called for duty!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("Unnamed", 100, 100, 30)
{
    std::cout << "A random FragTrap has been called for duty!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    *this = obj;
    std::cout << "Kage Bunshin no Jutsu!!! FragTrap clone named " << " has been called for duty!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap named " << name << " has died with honor. RIP!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
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

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap named " << name << " Says \"High five guys !\"" << std::endl;
}