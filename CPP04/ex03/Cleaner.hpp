#ifndef Cleaner_HPP
#define Cleaner_HPP

#include "Character.hpp"

class Cleaner
{
    public:
        Cleaner();
        Cleaner(const Cleaner &other);
        ~Cleaner();

        Cleaner &operator=(const Cleaner &other);
};


#endif