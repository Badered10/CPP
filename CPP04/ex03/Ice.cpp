#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &Ice) : AMateria(Ice) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &Ice) 
{
    AMateria::operator=(Ice);
    return *this;
}

AMateria *Ice::clone() const 
{
   return new Ice(*this);
}

void Ice::use(ICharacter &target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

