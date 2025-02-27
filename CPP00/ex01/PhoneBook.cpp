#include "PhoneBook.hpp"

void PhoneBook::add_contact(Contact new_contact)
{
    int i = 0;
    static int count;

    for (i = 0; i < 8 && *contact[i].get_element(0).c_str(); i++);
    if (i == 8)
    {
        contact[count] = new_contact;
        if (++count == 8)
            count = 0;
    }
    else
        contact[i] = new_contact;
}

Contact PhoneBook::get_contact(int pose)
{
    Contact con;
    if (pose >= 0 && pose <= 7)
        return (contact[pose]);
    return con;
}
