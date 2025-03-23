#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_name = name;

    this->HitPoints = FragTrap::HitPoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = ScavTrap::AttackDamage;
    std::cout << "DiamondTrap named " << _name << " has been called for duty!" << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap((std::string)"Unnamed" + "_clap_name"), ScavTrap("Unnamed"), FragTrap("Unnamed")
{
    this->_name = "Unnamed";
    this->HitPoints = FragTrap::HitPoints;
    this->EnergyPoints = ScavTrap::EnergyPoints;
    this->AttackDamage = ScavTrap::AttackDamage;
    std::cout << "A random DiamondTrap has been called for duty!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
    *this = obj;
    std::cout << "Kage Bunshin no Jutsu!!! DiamondTrap clone named " << _name << " has been called for duty!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap named " << _name << " has died with honor. RIP!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
    if (this != &obj)
    {
        this->_name = obj._name;
        this->setName(obj.getName());
        this->HitPoints = obj.HitPoints;
        this->EnergyPoints =  obj.EnergyPoints;
        this->AttackDamage =  obj.AttackDamage;
    }
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap named " << _name << " is also known as " << ClapTrap::name << std::endl;
}
