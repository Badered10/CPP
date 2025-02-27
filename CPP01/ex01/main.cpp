#include "Zombie.hpp"

int main()
{
    Zombie* dumbs = zombieHorde( 10 , "Dumb" );
    if (!dumbs)
        return (1);
    for (int i = 0; i < 10; i++)
        dumbs[i].announce();
    
    delete[] dumbs;
    
    return (0);
}
