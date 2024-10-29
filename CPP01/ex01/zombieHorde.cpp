#include "Zombie.hpp"

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
    if (N <= 0)
        return (NULL);

   Zombie* res = new Zombie[N];

    for (int i = 0; i < N; i++)
        new(&res[i])Zombie(name);
    
    return (res);
}
