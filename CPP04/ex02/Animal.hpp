# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);
        
        Animal &operator=(const Animal &other);
    public:
        virtual std::string getType() const;
        virtual void makeSound() const = 0;
        virtual ~Animal();
};

# endif