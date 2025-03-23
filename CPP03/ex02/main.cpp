#include "FragTrap.hpp"

int main()
{
    FragTrap T("Frag");

    std::cout << T.getName() << " " << T.getHP() << " " << T.getEP() << " " <<  T.getAD() << std::endl;

    std::cout << T.getEP() << std::endl;
    T.highFivesGuys();
    std::cout << T.getEP() << std::endl;
    T.attack("ENEMY");
    std::cout << T.getEP() << std::endl;
    T.takeDamage(21);
    std::cout << T.getHP() << std::endl;


}
