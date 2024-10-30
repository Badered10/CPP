#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
}
Weapon::Weapon()
{
}

const std::string &Weapon::getType()
{
    return (type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}
