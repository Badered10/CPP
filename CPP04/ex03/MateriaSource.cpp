# include "MateriaSource.hpp"
# include "garbge.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4 ; i++)
        materias[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
    *this = other;
}
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4 ; i++)
        delete materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4 ; i++)
            materias[i] = other.materias[i];
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4 ; i++)
    {
        if (materias[i] == NULL)
        {
            materias[i] = materia->clone();
            break;
        }
    }
    delete materia;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i]->getType() == type)
        {
            AMateria *tmp = materias[i]->clone();
            return tmp;
        }
    }
    return NULL;
}
