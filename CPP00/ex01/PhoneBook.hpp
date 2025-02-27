#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#ifdef ALL
#undef ALL
#endif

#ifndef ALL
#define ALL 5
#endif


#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contact[8];
    public:
        void    add_contact(Contact new_contact);
        Contact get_contact(int pose);
};

#endif