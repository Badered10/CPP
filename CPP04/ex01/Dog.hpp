#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;

    public:
        Dog();
        Dog(const Dog &dog);
        ~Dog();

        Dog &operator=(const Dog &dog);
        
        Brain *getBrain() const;
        void setBrain(Brain *brain);
        void makeSound() const;
};

#endif