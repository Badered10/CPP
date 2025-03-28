#ifndef GARBAGE_HPP
# define GARBAGE_HPP

#include "AMateria.hpp"

#include <iostream>


class Garbge
{
    private:
        AMateria *content;
        Garbge *next;
    public:
        Garbge();
        Garbge(const Garbge &other);
        Garbge(AMateria *content, Garbge *next);
        ~Garbge();

        Garbge &operator=(const Garbge &other);

        void delet_garbge(Garbge *list);
        void add_front(Garbge **list ,AMateria *content);
        
};

#endif