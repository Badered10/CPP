#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstring>
#include <ios>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib> 

int get_max(PhoneBook phone)
{
    int count = 0;

    while (phone.get_contact(count).get_element(0) != "")
        count++;
    return (count - 1);
}

bool    all_printables(char *str)
{
    while (isprint(*str))
        str++;
    return (!(*str));
}

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
std::string get_number(std::string message)
{
    std::string line;
    int count = 0;

    while ((all_spaces((char *)line.c_str()) || !all_digits((char *)line.c_str())) || !all_printables((char *)line.c_str()))
    {
        if (count >= 1)
            std::cout << "Bad input you must enter digits only\n"; 
        std::cout <<  message;
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit (0);
        count++;
    }
    return (line);
}

std::string get_input(std::string message)
{
    std::string line;
    while (all_spaces((char *)line.c_str()) || !all_printables((char *)line.c_str()))
    {
        std::cout <<  message;
        std::getline(std::cin, line);
        if (std::cin.eof())
            exit (0);
    }
    return (line);
}

void    show_table(PhoneBook phone)
{
    std::cout << "---------------------------------------------\n"
                << "| INDEX | FIRST NAME | LAST NAME | NICKNAME |\n"
                << "---------------------------------------------\n";
    for (int i = 0; phone.get_contact(i).get_element(0) != ""; i++)
    {
        std::cout << "|" << i << std::setw(9) << "";
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

void    search(PhoneBook phone, int max)
{
    std::string line;
    int         num;

    std::cout << "ENTERD TO SEARCH\n";
    if (max == -1)
    {
        std::cout << "No contacts to show !\n Try to add one using ""ADD"" \n";
        return;
    }
    show_table(phone);
    line = get_number("Enter index to see more details : ");
    num = atoi(line.c_str());
    if (num <= max && num >= 0)
        phone.get_contact(num).list_elements(ALL);
    else
        std::cout << "Index is out of range\t range is [0-" << max << "]" << std::endl;
}

void    intractive_mode()
{
    std::string line;
    PhoneBook phone;
    while (1)
    {
        line = get_input("Enter :");

        if(!std::strcmp("ADD", line.c_str()))
            add(&phone);
        else if (!std::strcmp("SEARCH", line.c_str()))
            search(phone, get_max(phone));
        else if (!std::strcmp("EXIT", line.c_str()))
            break;
    }
}

int main()
{
    intractive_mode();
    return (0);
}