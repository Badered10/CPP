#include "ScavTrap.hpp"

int main()
{
    ScavTrap T("HELL");

    std::cout << T.getEP() << std::endl;
    T.guardGate();
    std::cout << T.getEP() << std::endl;
    T.attack("ENEMY");
    std::cout << T.getEP() << std::endl;
    T.takeDamage(21);
    std::cout << T.getHP() << std::endl;


}
