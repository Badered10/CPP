#include "Zombie.hpp"

// It creates a zombie, name it, and return it so you can use it outside of the function scope
Zombie* newZombie( std::string name )
{
    Zombie*new_zombie;

    new_zombie = new Zombie(name);
    return (new_zombie);
}

/*
 It must allocate N Zombie objects in a single allocation. Then, it has to initialize the
zombies, giving each one of them the name passed as parameter. The function returns a
pointer to the first zombie.
Implement your own tests to ensure your zombieHorde() function works as expected.
Try to call announce() for each one of the zombies.
Don’t forget to delete all the zombies and check for memory leaks.
*/
Zombie* zombieHorde( int N, std::string name )
{
   Zombie* res = new Zombie[N];
   
    for (int i = 0; i < N; i++)
        new(&res[i])Zombie( name );
    
    return (res);
}

int main()
{
    Zombie* dumbs = zombieHorde( 10 , "Dumb" );
    for (int i = 0; i < 10; i++)
        dumbs[i].announce();
    
    delete[] dumbs;
    
    return (0);
}
