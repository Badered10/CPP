#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    {
        const int size = 4;
    
        std::cout << "------------------------Basic Tests-------------------------" << std::endl;
        Animal *animals[size];
    
       Cat catA;
       Cat copycatA = catA;
       Dog DogA;
       Dog copyDogA = DogA;


    
       DogA = copyDogA;
       DogA = copyDogA;

    
        std::cout << "------------------------Deep Copy-------------------------" << std::endl;
    
        std::cout << "copy brain address: " << catA.getBrain() << std::endl;
        std::cout << "original brain address: " << copycatA.getBrain() << std::endl;
    
    
        std::cout << "copy brain address: " << DogA.getBrain() << std::endl;
        std::cout << "original brain address: " << copyDogA.getBrain() << std::endl;
    
    
        std::cout << "------------------------Fill Array-------------------------" << std::endl;
        for (int i = 0; i < size / 2; i++)
        {
            animals[i] = new Dog();
        }
        for (int i = size / 2 ; i < size; i++)
        {
            animals[i] = new Cat();
        }

        std::cout << "------------------------SOUND TESTS-------------------------" << std::endl;
        for (int i = 0; i < size; i++)
        {
            animals[i]->makeSound();
        }
        std::cout << "------------------------TYPE TESTS -------------------------" << std::endl;

        for (int i = 0; i < size; i++)
        {
            std::cout << animals[i]->getType() << std::endl;
        }
        std::cout << "------------------------DELETING-------------------------" << std::endl;

        for (int i = 0; i < size; i++)
        {
            delete animals[i];
        }
    
        return (0);
    }

    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
        return 0;
    }

    {
        const Animal j;
        const Animal i;
        return 0;
    }

}