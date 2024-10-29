
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string str)
{
    name = str;
}

Zombie::~Zombie(void)
{
    std::cout << name << ": Has been cleaned up !" << std::endl;
}
void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

