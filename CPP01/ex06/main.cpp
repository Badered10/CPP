#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Args must be 2\n";
        return (1);
    }

    Harl harly;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    std::string level = av[1];
    int i = 0;

    while (level != levels[i] && i < 4)
        i++;

    switch (i)
    {
        case 0 :
            std::cout << "[ " << levels[0] << " ]" << std::endl;
            harly.complain(levels[0]);
            std::cout << std::endl;
        case 1 :
            std::cout << "[ " << levels[1] << " ]" << std::endl;
            harly.complain(levels[1]);
            std::cout << std::endl;
        case 2 :
            std::cout << "[ " << levels[2] << " ]" << std::endl;
            harly.complain(levels[2]);
            std::cout << std::endl;
        case 3 :
            std::cout << "[ " << levels[3] << " ]" << std::endl;
            harly.complain(levels[3]);
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std:: endl;
        }
}