#include "AMateria.hpp"

AMateria::AMateria() : _type("none") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & other)
{
    *this = other;
}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(AMateria const & other) 
{
    if (this != &other) 
        this->_type = other._type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter & target) 
{
    (void) target;
}
