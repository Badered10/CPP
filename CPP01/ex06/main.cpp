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

    if (i == 4)
       i = -1;

    while( i < 4 )
    {
        switch (i)
        {
            case 0:
                std::cout << "[ " << levels[i] << " ]" << std::endl;
                harly.complain(levels[i]);
                std::cout << std::endl;
                break;
            case 1:
                std::cout << "[ " << levels[i] << " ]" << std::endl;
                harly.complain(levels[i]);
                std::cout << std::endl;
                break;
            case 2:
                std::cout << "[ " << levels[i] << " ]" << std::endl;
                harly.complain(levels[i]);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "[ " << levels[i] << " ]" << std::endl;
                harly.complain(levels[i]);
                std::cout << std::endl;
                break;
            default:
                std::cout << "[ Probably complaining about insignificant problems ]" << std:: endl;
                i = 3;
                break;
        }
        i++;
    }
}