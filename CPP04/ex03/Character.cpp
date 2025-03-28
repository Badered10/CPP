#include "Character.hpp"

Garbge* Character::grave = new Garbge();

Character::Character() : name("Unnamed")
{
    std::cout << "Unnamed Character has being respawn !" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string name) : name(name)
{
    std::cout << name << " has being respawn !" << std::endl;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &other)
{
    *this = other;
}

Character::~Character()
{
    std::cout << name << " has being destroyed !" << std::endl;
}

void Character::clean_grave(void)
{
    grave->delet_garbge(grave);
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
    if (!m)
    {
        std::cout << name << " cannot equip a vide Materia" << std::endl;
        return;
    }
    grave->add_front(&grave, m);
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            std::cout << name << " equiped new Materia of type : " << m->getType() << std::endl;
            return ;
        }
    }
    std::cout << name << " cannot equip new Materia ! Inventory is full." << std::endl;
}

void Character::unequip(int idx) 
{
    if (idx < 0 || idx > 3)
    {
        std::cout << name << " cannot unequip a Materia ! Invalid index at [" << idx << "]." << std::endl;
        return;
    }
    if (inventory[idx] == NULL)
    {
        std::cout << name << " cannot unequip a Materia ! Materia already unequiped." << std::endl;
        return;
    }
    grave->add_front(&grave, inventory[idx]);
    inventory[idx] = NULL;
    std::cout << name << " unequiped the Materia at index :[" << idx << "]!" << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << name << " cannot use a Materia ! Invalid index at [" << idx << "]."  << std::endl;
        return;
    }
    if (inventory[idx] == NULL)    
    {
        std::cout << name << " cannot use a Materia ! Inventory slot is vide at [" << idx << "]." << std::endl;
        return;
    }
    inventory[idx]->use(target);
}
