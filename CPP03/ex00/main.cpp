#include "ClapTrap.hpp"

int main()
{
    ClapTrap naruto("Naruto");
    ClapTrap clone(naruto);
    ClapTrap saske("Saske");

    std::cout << "\n--- BATTLE STARTS ---\n" << std::endl;

    naruto.attack("SASKEEEEEEE");
    saske.takeDamage(4);

    saske.attack("Naruto");
    naruto.takeDamage(5);

    std::cout << "\n--- HEALING TEST ---\n" << std::endl;
    naruto.beRepaired(3);

    std::cout << "\n--- FINISHER MOVE ---\n" << std::endl;
    naruto.takeDamage(10);
    naruto.attack("Saske");
    naruto.beRepaired(5);

    std::cout << "\n--- ENERGY DRAIN TEST ---\n" << std::endl;
    for (int i = 0; i < 10; i++)
        saske.attack("Naruto");

    saske.attack("Naruto");
    saske.beRepaired(2);

    std::cout << "\n--- END OF TESTS ---\n" << std::endl;
}
