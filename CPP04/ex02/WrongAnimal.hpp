#ifndef WorngAnimal_HPP
# define WorngAnimal_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
    
        WrongAnimal &operator=(const WrongAnimal &other);

        std::string getType() const;
        void makeSound() const;
};

#endif