#ifndef GARBAGE_HPP
# define GARBAGE_HPP

#include "AMateria.hpp"

#include <iostream>


struct garbge
{
    AMateria *content;
    garbge *next;
    garbge();
    void delet_garbge();
    void add_front(AMateria *content);
};


#endif