#include "PhoneBook.hpp"
#include <cstring>
#include <ios>
#include <iostream>
#include <string>


void PhoneBook::add_contact(Contact new_contact)
{
    for (int i = 0; i < 7; i++)
        PhoneBook::contact[i] = PhoneBook::contact[i + 1];
    PhoneBook::contact[7] = new_contact;
}

Contact PhoneBook::get_contact(int pose)
{
    if (pose >= 0 && pose <= 7)
        return(PhoneBook::contact[pose]);
    return err;
}

void Contact::add_element(std::string infos, int id)
{
    switch (id)
    {
        case FIRST_NAME:
            first_name = infos;
            break;
        case LAST_NAME:
            last_name = infos;
            break;
        case NICKNAME:
            nickname = infos;
            break;
        case PHONE_NUMBER:
            phone_number = infos;
            break;
        case DARKEST_SECRET:
            darkest_secret = infos;
            break;    
    default:
        break;
    }
}
std::string Contact::get_element(int id)
{
    switch (id)
    {
        case FIRST_NAME:
            return (first_name);
            break;
        case LAST_NAME:
            return (last_name);
            break;
        case NICKNAME:
            return (nickname);
            break;
        case PHONE_NUMBER:
            return (phone_number);
            break;
        case DARKEST_SECRET:
            return (darkest_secret);
            break;    
    default:
        return("");
        break;
    }
}

int main()
{
    std::string line;
    PhoneBook phone;
    while (1)
    {
        std::cout << "Enter : ";
        std::getline(std::cin, line);
        if(!std::strcmp("ADD", line.c_str()))
        {
            Contact con;
            std::cout << "Enter FIRST NAME : ";
            std::getline(std::cin, line);
            con.add_element(line, Contact::FIRST_NAME);
            phone.add_contact(con);
        }
        else if (!std::strcmp("EXIT", line.c_str()))
            break;
    }
    for(int i = 0; i < 8; i++)
    {
        std::string str;
        str =  phone.get_contact(i).get_element(Contact::FIRST_NAME);
        if (std::strcmp("", str.c_str()))
            std::cout << str << std::endl;
    }
    return (0);
}