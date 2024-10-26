#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#ifndef ALL
#define ALL 5
#endif


#include <string>
#include <cctype>


class Contact // first name, last name, nickname, phone number, darkest secret
{
private:
    std::string infos[5];
public:
    enum info_id
    {
        FIRST_NAME = 0,
        LAST_NAME,
        NICKNAME,
        PHONE_NUMBER,
        DARKEST_SECRET
    };
    void        add_element(std::string data, int pose);
    std::string get_element(int pose);
    void        list_elements(int elements_num);
};

class PhoneBook
{
private:
    Contact contact[8];
public:
    void    add_contact(Contact new_contact);
    Contact get_contact(int pose);
    Contact err;
};

#endif