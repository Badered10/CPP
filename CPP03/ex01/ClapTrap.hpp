#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
    std::string name;
    unsigned int HitPoints;
    unsigned int EnergyPoints;
    unsigned int AttackDamage;
    public:
        ClapTrap();
        ClapTrap(std::string name, unsigned int Hp, unsigned int Ep, unsigned int Ad);
        ClapTrap(const ClapTrap &obj);
        ClapTrap& operator=(const ClapTrap& obj);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int  amount);
        void beRepaired(unsigned int  amount);
        unsigned int getHP(void) const;
        unsigned int getEP(void) const;
        unsigned int getAD(void) const;
        std::string getName(void) const;
        void setHP(unsigned int HitPoints);
        void setEP(unsigned int EnergyPoints);
        void setAD(unsigned int AttackDamage);
        void setName(std::string new_name);
};

#endif