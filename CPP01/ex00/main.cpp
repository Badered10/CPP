#include "Zombie.hpp"

int main()
{
    Zombie *tmp = newZombie("heap zombie");

    tmp->announce();
    delete(tmp);

    randomChump("stack zombie");

    return (0);
}
