#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    if (this == &other)
        return (*this);
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(const std::string &idea)
{
    for (int i = 0; i < 100; i++)
    {
        if (ideas[i].empty())
        {
            ideas[i] = idea;
            break;
        }
    }
}

std::string Brain::getIdea(int idx) const
{
    if (idx < 0 || idx >= 100)
        return ("");
    if (!ideas[idx].empty())
        return (ideas[idx]);
    return ("");
}
