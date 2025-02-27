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
        Fixed& operator=(const Fixed& obj);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed(const int parm);
        Fixed(const float param);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &s, const Fixed& obj);

#endif