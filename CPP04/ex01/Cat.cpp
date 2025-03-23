#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow 🦁!" << std::endl;
}

Brain *Cat::getBrain() const
{
    return brain;
}

void Cat::setBrain(Brain *brain)
{
    delete this->brain;
    this->brain = brain;
}

