#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(AMateria const & src) {
    *this = src;
}

AMateria::~AMateria() {}

AMateria & AMateria::operator=(AMateria const & src) {
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}


std::string const & AMateria::getType() const {
    return this->_type;
}


void AMateria::use(ICharacter & target) {
    (void)target;
}
