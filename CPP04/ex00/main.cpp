#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() // zid
{
    const Animal* meta = new Animal();
    const WrongAnimal* beta = new WrongAnimal();

    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* a = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << a->getType() << " " << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    std::cout << beta->getType() << " " << std::endl;

    a->makeSound();
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    
    meta->makeSound();
    beta->makeSound();

    delete j;
    delete i;
    delete a;

    delete meta; 
    delete beta;
    return 0;
}