#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    (void)name;
    if (N <= 0)
        return (NULL);

   Zombie* res = new Zombie[N]; // [0 ---> N - 1], [ ... ]

    // for (int i = 0; i < N; i++)
    //     new(&res[i])Zombie(name);
    
    return (res);
}
