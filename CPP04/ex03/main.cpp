#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Garbge.hpp"
#include "Cleaner.hpp"

static Cleaner clean;

int main()
{
    std::cout << "---------------- Creating players -------------------" << std::endl;

    ICharacter* alice = new Character("alice");
    ICharacter* rex = new Character("rex");
    ICharacter* alex = new Character("alex");
    ICharacter* thorfinn = new Character("thorfinn");

    std::cout << "---------------- Creating MateriaSource -------------------" << std::endl;

    IMateriaSource *source = new MateriaSource();

    std::cout << "---------------- Learn Materias -------------------" << std::endl;

    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Ice());
    source->learnMateria(new Cure());
    source->learnMateria(new Cure());

    std::cout << "---------------- Equip Materias -------------------" << std::endl;

    AMateria *same_materia;

    same_materia = source->createMateria("ice");
    alice->equip(source->createMateria("ice"));
    alice->equip(source->createMateria("cure"));
    alice->equip(source->createMateria("ice"));
    alice->equip(source->createMateria("ice"));
    alice->equip(source->createMateria("ice"));
    alice->equip(same_materia);
    alice->equip(same_materia);
    alice->equip(same_materia);
    alice->equip(source->createMateria("ice"));
    alice->equip(source->createMateria("!!!!!!"));
    alice->equip(same_materia);

    alex->equip(source->createMateria("ice"));
    alex->equip(source->createMateria("cure"));
    alex->equip(source->createMateria("ice"));
    alex->equip(source->createMateria("worng"));
    alex->equip(same_materia);

    rex->equip(source->createMateria("ice"));
    rex->equip(source->createMateria("cure"));
    rex->equip(source->createMateria("ice"));
    rex->equip(source->createMateria("????"));
    rex->equip(same_materia);

    thorfinn->equip(NULL);
    thorfinn->equip(NULL);
    thorfinn->equip(NULL);
    thorfinn->equip(NULL);

    std::cout << "---------------- Battle Log -------------------" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        rex->use(i, *alex);
        rex->use(i, *alice);

        alex->use(i, *alex);
        alex->use(i, *rex);

        alice->use(i, *alex);
        alice->use(i, *rex);

        thorfinn->use(i, *alex);
        thorfinn->use(i, *rex);
        thorfinn->use(i, *alice);
    }

    std::cout << "---------------- Unequip Materias -------------------" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        rex->unequip(i);

        alex->unequip(i);

        alice->unequip(i);

        thorfinn->unequip(i);

        thorfinn->unequip(-i);
    }

    std::cout << "---------------- Battle 2 Log -------------------" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        rex->use(i, *alex);
        rex->use(i, *alice);

        alex->use(i, *alex);
        alex->use(i, *rex);

        alice->use(i, *alex);
        alice->use(i, *rex);

        thorfinn->use(i, *alex);
        thorfinn->use(i, *rex);
        thorfinn->use(i, *alice);
    }

    std::cout << "---------------- Equip Materias -------------------" << std::endl;

    AMateria *random = NULL;

    for (int i = 0; i < 10; i++)
    {
        rex->equip(new Ice());

        alex->equip(new Cure());

        alice->equip(random);

        thorfinn->equip(NULL);
    }

        std::cout << "---------------- Battle 3 Log -------------------" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        rex->use(i, *alex);
        rex->use(i, *alice);

        alex->use(i, *alex);
        alex->use(i, *rex);

        alice->use(i, *alex);
        alice->use(i, *rex);
    }

    std::cout << "---------------- End tests -------------------" << std::endl;

    delete alex;
    delete alice;
    delete rex;
    delete thorfinn;
    delete source;
    return 0;
}
