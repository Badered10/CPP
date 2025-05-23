#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;

    public:
        Cat();
        Cat(const Cat &other);
        virtual ~Cat();

        Cat &operator=(const Cat &other);

        Brain *getBrain() const;
        void setBrain(Brain *brain);
        void makeSound() const;
};

#endif