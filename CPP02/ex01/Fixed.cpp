#include "Fixed.hpp"

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
        fixed_point = obj.fixed_point;
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

Fixed::Fixed(const int param)
{
    std::cout <<  "Int constructor called" << std::endl;
    fixed_point = param << n_fractional_bits;
}

Fixed::Fixed(const float param)
{
    std::cout <<  "Float constructor called" << std::endl;
    fixed_point = roundf( param  *  (1 << n_fractional_bits));
}


std::ostream& operator<<(std::ostream &s, const Fixed& obj)
{
    s << obj.toFloat();
    return (s);
}


float Fixed::toFloat( void ) const
{
    return ((float)fixed_point / (1 << n_fractional_bits));
}

int Fixed::toInt( void ) const
{
    return (fixed_point >> n_fractional_bits);
}
