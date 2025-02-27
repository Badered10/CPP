#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <bits/stdc++.h>

class Fixed
{
    private:
        int  fixed_point;
        static const int   n_fractional_bits;
    
    public:
        Fixed();
        Fixed(const Fixed &obj);
        Fixed(const int parm);
        Fixed(const float param);
        ~Fixed();

        Fixed& operator=(const Fixed& obj);
        bool operator>(const Fixed& obj)const ;
        bool operator<(const Fixed& obj);
        bool operator>=(const Fixed& obj);
        bool operator<=(const Fixed& obj);
        bool operator==(const Fixed& obj);
        bool operator!=(const Fixed& obj);

        Fixed operator+(const Fixed& obj);
        Fixed operator-(const Fixed& obj);
        Fixed operator*(const Fixed& obj);
        Fixed operator/(const Fixed& obj);

        Fixed& operator--();
        Fixed& operator++();
        Fixed operator--(int);
        Fixed operator++(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &s, const Fixed& obj);

#endif