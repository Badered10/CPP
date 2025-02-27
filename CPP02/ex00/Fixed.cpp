#include "Fixed.hpp"
#include <iostream>

const int   Fixed::n_fractional_bits = 8;

Fixed::Fixed()
{
    std::cout <<  "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout <<  "Copy constructor called" << std::endl;
    *this = obj; 
}
Fixed& Fixed::operator=(const Fixed& obj)
{
    std::cout <<  "Copy assignment operator called" << std::endl;
    if (this != &obj)
        fixed_point = obj.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout <<  "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout <<  "getRawBits member function called" << std::endl;
    return (fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}