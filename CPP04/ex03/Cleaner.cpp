# include "Cleaner.hpp"

Cleaner::Cleaner()
{

}

Cleaner::~Cleaner()
{
    Character::clean_grave();
}

Cleaner::Cleaner(const Cleaner &other)
{
    *this = other;
}

Cleaner &Cleaner::operator=(const Cleaner &other)
{
    (void)other;
    return (*this);
}
