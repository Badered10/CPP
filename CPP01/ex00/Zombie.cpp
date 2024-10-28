
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    void announce( void );
    Zombie(std::string str);
    ~Zombie(void);
};

Zombie::Zombie(std::string str)
{
    name = str;
}

Zombie::~Zombie(void)
{
    std::cout << name << ": Has been cleaned up !" << std::endl;
}
void Zombie::announce( void )
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
