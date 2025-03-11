#include "Fixed.hpp"

const int   Fixed::n_fractional_bits = 8;

Fixed::Fixed()
{
    fixed_point = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj; 
}
Fixed& Fixed::operator=(const Fixed& obj)
{
    if (this != &obj)
        fixed_point = obj.fixed_point;
    return *this;
}

bool Fixed::operator>(const Fixed& obj) const
{
    return (this->fixed_point > obj.fixed_point);
}
bool Fixed::operator<(const Fixed& obj)
{
    return (this->fixed_point < obj.fixed_point);
}
bool Fixed::operator>=(const Fixed& obj)
{
    return (this->fixed_point >= obj.fixed_point);
}
bool Fixed::operator<=(const Fixed& obj)
{
    return (this->fixed_point <= obj.fixed_point);
}
bool Fixed::operator==(const Fixed& obj)
{
    return (this->fixed_point == obj.fixed_point);
}
bool Fixed::operator!=(const Fixed& obj)
{
    return (this->fixed_point != obj.fixed_point);
}


Fixed Fixed::operator+(const Fixed& obj)
{
    Fixed res;
    res.fixed_point = this->fixed_point + obj.fixed_point;
    return (res);
}
Fixed Fixed::operator-(const Fixed& obj)
{
    Fixed res;
    res.fixed_point = this->fixed_point - obj.fixed_point;
    return (res);
}
Fixed Fixed::operator*(const Fixed& obj)
{
    Fixed res;
    // std::cout << ((this->fixed_point * obj.fixed_point) >> n_fractional_bits) << "\n" ;
    // std::cout << (int)((this->toFloat() * obj.toFloat()) * (1 << n_fractional_bits)) << "\n" ;
    res.fixed_point = (this->fixed_point * obj.fixed_point) >> n_fractional_bits;
    return (res);
}
Fixed Fixed::operator/(const Fixed& obj)
{
    Fixed res;
    // std::cout << ((this->fixed_point << n_fractional_bits) / obj.fixed_point) << "\n" ;
    // std::cout << roundf((this->toFloat() / obj.toFloat() * (1 << n_fractional_bits))) << "\n" ;
    res.fixed_point = (this->fixed_point << n_fractional_bits) / obj.fixed_point;
    return (res);
}

Fixed& Fixed::operator--()
{
    this->fixed_point--;
    return (*this);
}
Fixed& Fixed::operator++()
{
    this->fixed_point++;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed res;

    res = *this;
    this->fixed_point--;
    return (res);
}
Fixed Fixed::operator++(int)
{
    Fixed res;

    res = *this;
    this->fixed_point++;
    return (res);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a > b)
        return (b);
    else
        return (a);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed&  b)
{
    if (a > b)
        return (b);
    else
        return (a);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits( void ) const
{
    return (fixed_point);
}

void Fixed::setRawBits( int const raw )
{
    fixed_point = raw;
}

Fixed::Fixed(const int param)
{
    fixed_point = param << n_fractional_bits;
}

Fixed::Fixed(const float param)
{
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
