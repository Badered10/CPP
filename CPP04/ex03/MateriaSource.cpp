# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "A MateriaSource has being created !" << std::endl;
    for (int i = 0; i < 4 ; i++)
        slots[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
    *this = other;
}
MateriaSource::~MateriaSource()
{
    std::cout << "A MateriaSource has being destroyed !" << std::endl;
    for (int i = 0; i < 4 ; i++)
        delete slots[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4 ; i++)
            slots[i] = other.slots[i];
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia) 
{
    bool learned = false;
    for (int i = 0; i < 4 ; i++)
    {
        if (slots[i] == NULL)
        {
            slots[i] = materia->clone();
            learned = true;
            std::cout << "A MateriaSource has being learned a new Materia of type : " << slots[i]->getType() << " !"<< std::endl;
            break;
        }
    }
    if (!learned)
        std::cout << "A MateriaSource cannot learned a new Materia, slots are full !"<< std::endl;
    delete materia;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i]->getType() == type)
        {
            AMateria *clone = slots[i]->clone();
            std::cout << "A MateriaSource create a new Materia of type "<< clone->getType() << " !"<< std::endl;
            return clone;
        }
    }
    return NULL;
}
