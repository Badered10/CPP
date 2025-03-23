#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>

class Cure : public AMateria
{
    public:
        Cure();
        virtual ~Cure();
        Cure(Cure const & src);
        Cure & operator=(Cure const & src);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
        clone();
};

#endif