#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
private:
   std::string type;
public:
    const std::string &getType();
    void setType(std::string);
    Weapon(void);
    Weapon(std::string);
    ~Weapon();
};


#endif