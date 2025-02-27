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
            case 0:
            std::cout << "First name: ";
            break;
            case 1:
            std::cout << "Last name: ";
            break;
            case 2:
            std::cout << "Nickname: ";
            break;
            case 3:
            std::cout << "Phone number: ";
            break;
            case 4:
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
    if (pose >= 0 && pose <= 4)
        return (infos[pose]);
    return (NULL);
}
