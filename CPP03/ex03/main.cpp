#include "DiamondTrap.hpp"

int main()
{
    ClapTrap A("CLAP");
    ScavTrap B("Scav");
    FragTrap C("Frag");
    DiamondTrap D("Diamond");


    std::cout << A.getName() << " " << A.getHP() << " " << A.getEP() << " " <<  A.getAD() << std::endl;
    std::cout << B.getName() << " " << B.getHP() << " " << B.getEP() << " " <<  B.getAD() << std::endl;
    std::cout << C.getName() << " " << C.getHP() << " " << C.getEP() << " " <<  C.getAD() << std::endl;    
    std::cout << D.getName() << " " << D.getHP() << " " << D.getEP() << " " <<  D.getAD() << std::endl;


    std::cout << "------------CLAP TESTS-------------" << std::endl;
    std::cout << A.getEP() << std::endl;
    std::cout << A.getEP() << std::endl;
    A.attack("ENEMY");
    std::cout << A.getEP() << std::endl;
    A.takeDamage(21);
    std::cout << A.getHP() << std::endl;

    std::cout << "------------SCAV TESTS-------------" << std::endl;
    std::cout << B.getEP() << std::endl;
    std::cout << B.getEP() << std::endl;
    B.attack("ENEMY");
    std::cout << B.getEP() << std::endl;
    B.takeDamage(21);
    std::cout << B.getHP() << std::endl;
    B.guardGate();


    std::cout << "------------FRAG TESTS-------------" << std::endl;
    std::cout << C.getEP() << std::endl;
    C.highFivesGuys();
    std::cout << C.getEP() << std::endl;
    C.attack("ENEMY");
    std::cout << C.getEP() << std::endl;
    C.takeDamage(21);
    std::cout << C.getHP() << std::endl;


    std::cout << "------------DIAMOND TESTS-------------" << std::endl;
    std::cout << D.getEP() << std::endl;
    D.highFivesGuys();
    std::cout << D.getEP() << std::endl;
    D.attack("ENEMY");
    std::cout << D.getEP() << std::endl;
    D.takeDamage(21);
    std::cout << D.getHP() << std::endl;
    D.guardGate();
    D.whoAmI();

    std::cout << "---------------------------------------------------" << std::endl;


}