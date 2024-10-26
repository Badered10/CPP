#include "PhoneBook.hpp"
#include <cstring>
#include <ios>
#include <iostream>
#include <string>
#include <cctype>


bool    not_all_space(char *str)
{
    while (isspace(*str))
        str++;
    return (*str);
}

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

void Contact::add_element(std::string data, int pose)
{
    if (pose >= 0 && pose <= 7)
        infos[pose] = data;

}
std::string Contact::get_element(int pose)
{
    if (pose >= 0 && pose <= 7)
        return (infos[pose]);
    return (NULL);
}

std::string get_input(std::string message)
{
    std::string line;
    while (!not_all_space((char *)line.c_str()))
    {
        std::cout <<  message;
        std::getline(std::cin, line);
    }
    return (line);
}


int main()
{
    std::string line;
    PhoneBook phone;
    while (1)
    {
        line = get_input("Enter :");
        if(!std::strcmp("ADD", line.c_str()))
        {
            Contact con;
            con.add_element(get_input("Enter first name : "), Contact::FIRST_NAME);
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