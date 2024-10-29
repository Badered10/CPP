#ifndef  ZOMBIE_HPP
#define  ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
    std::string name;
    public:
        void announce( void );
        Zombie(void);
        Zombie(std::string str);
        ~Zombie(void);
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif