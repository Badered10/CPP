#include "Zombie.hpp"

int main()
{
    Zombie *tmp = newZombie("heap zombie");
    if (!tmp)
        return (1);

    tmp->announce();

    delete(tmp);

    randomChump("stack zombie");

    return (0);
}
