#include "Character.hpp"

Character::Character() : name("Unnamed")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &other)
{
    *this = other;
}

Character::~Character()
{
    // remove list of unequiped materias 
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; i++)
        {
            if (inventory[i] != NULL)
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return (*this);
}

std::string const & Character::getName() const 
{
    return (name);
}

void Character::equip(AMateria* m) 
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) 
{
    if (idx < 0 || idx > 4)
        return;
    if (inventory[idx] == NULL)
        return;
    // Drop on the floor
    inventory[idx] == NULL;
}

void Character::use(int idx, ICharacter& target) 
{
    if (idx < 0 || idx > 4)
        return;
    if (inventory[idx] == NULL)
        return;
    inventory[idx]->use(target);
}
