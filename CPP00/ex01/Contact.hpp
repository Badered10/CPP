# ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

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


#endif