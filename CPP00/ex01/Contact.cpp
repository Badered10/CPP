#include "Contact.hpp"
#include <iostream>

void        Contact::list_elements(int elements_num)
{
    std::string str;

    for (int i = 0; i < elements_num; i++)
    {
        str = get_element(i);
        switch (i)
        {
            case FIRST_NAME:
            std::cout << "First name: ";
            break;
            case LAST_NAME:
            std::cout << "Last name: ";
            break;
            case NICKNAME:
            std::cout << "Nickname: ";
            break;
            case PHONE_NUMBER:
            std::cout << "Phone number: ";
            break;
            case DARKEST_SECRET:
            std::cout << "Darkest secret: ";
            break;
        }
        if (*str.c_str())
            std::cout << str << std::endl;
    }
}

void Contact::add_element(std::string data, int pose)
{
    if (pose >= 0 && pose <= 7)
        infos[pose] = data;
}
std::string Contact::get_element(int pose)
{
    if (pose >= FIRST_NAME && pose <= DARKEST_SECRET)
        return (infos[pose]);
    return (NULL);
}
