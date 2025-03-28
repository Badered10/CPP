#include "Garbge.hpp"


Garbge::Garbge(AMateria *content ,Garbge *next) :content(content), next(next)
{

}

Garbge::Garbge() :content(NULL), next(NULL)
{

}
Garbge::Garbge(const Garbge &other)
{
    *this = other;
}
Garbge::~Garbge() {}

Garbge &Garbge::operator=(const Garbge &other)
{
    if (this != &other)
    {
        this->content = other.content;
        this->next = other.next;
    }
    return (*this);
}

void Garbge::add_front(Garbge **list ,AMateria *content)
{
    if (content == NULL)
        return;
    Garbge* tmp = *list;
    while (tmp) 
    {
        if (tmp->content == content)
            return;
        tmp = tmp->next;
    }
    Garbge *new_node = new Garbge(content, *list);
    *list = new_node;
}

void Garbge::delet_garbge(Garbge *list)
{
    Garbge *next;
    next = NULL;
    while (list)
    {
        next = list->next;
        if (list->content)
            delete list->content;
        delete list;
        list = next;
    }
}



