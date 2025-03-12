#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:

    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &obj);
    FragTrap& operator=(const FragTrap& obj);
    ~FragTrap();
    void highFivesGuys(void);
    
};

#endif