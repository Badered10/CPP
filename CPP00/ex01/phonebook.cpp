#include "PhoneBook.hpp"
#include <cstring>
#include <ios>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>


bool    all_digits(char *str)
{
    while (isdigit(*str))
        str++;
    return (!(*str));
}

bool    all_spaces(char *str)
{
    while (isspace(*str))
        str++;
    return (!(*str));
}

void    show_table(PhoneBook phone)
{
    for (int i = 0; i < 8 ; i++)
    {
        std::cout << i << std::setw(9) << "";
        for (int j = 0; j < 3; j++)
        {
            size_t len;

            len = strlen(phone.get_contact(i).get_element(j).c_str());
            if (len > 10)
            {
                std::cout << "|" << phone.get_contact(i).get_element(j).substr(0, 9) << ".";
            }
            else
                std::cout << "|"  << phone.get_contact(i).get_element(j) << std::setw(10 - len) << "";
        }
        std::cout << "|";
        std::cout << std::endl;
    }  
}
void        Contact::list_elements(int elements_num)
{
    std::string str;

    for (int i = 0; i < elements_num; i++)
    {
        str = get_element(i);
        if (*str.c_str())
            std::cout << str << std::endl;
    }
}
void PhoneBook::add_contact(Contact new_contact)
{
    int i = 0;

    for (i = 0; i < 8 && *contact[i].get_element(0).c_str(); i++);
    if (i == 8)
    {
        for (int i = 0; i < 7; i++)
            contact[i] = contact[i + 1];
        i = 7;
    }
    contact[i] = new_contact;
}

Contact PhoneBook::get_contact(int pose)
{
    Contact con;
    if (pose >= 0 && pose <= 7)
        return (contact[pose]);
    return con;
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

std::string get_number(std::string message)
{
    std::string line;
    while (all_spaces((char *)line.c_str()) || !all_digits((char *)line.c_str()))
    {
        std::cout <<  message;
        std::getline(std::cin, line);
    }
    return (line);
}

std::string get_input(std::string message)
{
    std::string line;
    while (all_spaces((char *)line.c_str()))
    {
        std::cout <<  message;
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit (0);
    }
    return (line);
}

void    add(PhoneBook *phone)
{
    Contact con;

    con.add_element(get_input("Enter first name : "), Contact::FIRST_NAME);
    con.add_element(get_input("Enter last name : "), Contact::LAST_NAME);
    con.add_element(get_input("Enter nickname : "), Contact::NICKNAME);
    con.add_element(get_number("Enter phone number : "), Contact::PHONE_NUMBER);
    con.add_element(get_input("Enter darkest secret : "), Contact::DARKEST_SECRET);
    phone->add_contact(con);
}

void    search(PhoneBook phone)
{
    std::string line;
    int         num;

    show_table(phone);
    line = get_input("Enter index to see more details : ");
    num = atoi(line.c_str());
    if (num <= 7 && num >= 0)
        phone.get_contact(num).list_elements(ALL);
    else
        std::cout << "Invlid index" << std::endl;
}

void    intractive_mode(void)
{
    std::string line;
    PhoneBook phone;
    while (1)
    {
        line = get_input("Enter :");

        if(!std::strcmp("ADD", line.c_str()))
            add(&phone);
        else if (!std::strcmp("SEARCH", line.c_str()))
            search(phone);
        else if (!std::strcmp("EXIT", line.c_str()))
            break;
    }
}

int main()
{
    intractive_mode();
    return (0);
}