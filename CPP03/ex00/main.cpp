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
    naruto.beRepaired(3);  // Should work (HP = 8)
    naruto.beRepaired(5);  // Should cap at 10 HP

    std::cout << "\n--- FINISHER MOVE ---\n" << std::endl;
    naruto.takeDamage(10); // Naruto should "die"
    naruto.attack("Saske"); // Should not work
    naruto.beRepaired(5); // Should not work

    std::cout << "\n--- ENERGY DRAIN TEST ---\n" << std::endl;
    for (int i = 0; i < 10; i++) // Drain energy completely
        saske.attack("Naruto");

    saske.attack("Naruto"); // Should fail (0 energy)
    saske.beRepaired(2); // Should fail (0 energy)

    std::cout << "\n--- END OF TESTS ---\n" << std::endl;
}
