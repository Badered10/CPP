#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#ifndef ACTIVE
#define ACTIVE 1
#endif

#ifndef INACTIVE
#define INACTIVE 0
#endif


#include <string>

class Contact // first name, last name, nickname, phone number, darkest secret
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
public:
    enum info_id
    {
        FIRST_NAME = 1,
        LAST_NAME,
        NICKNAME,
        PHONE_NUMBER,
        DARKEST_SECRET
    };
    void        add_element(std::string infos, int id);
    std::string get_element(int id);
};

class PhoneBook
{
private:
    Contact contact[8];
public:
    void add_contact(Contact new_contact);
    Contact get_contact(int pose);
    Contact err;
};

#endif