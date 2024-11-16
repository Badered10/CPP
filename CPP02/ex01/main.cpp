#include <iostream>
#include <math.h>
#include "Fixed.hpp"

int main( void ) 
{
// Fixed a;
// Fixed b( a );
// Fixed c;
// c = b;
// std::cout << a.getRawBits() << std::endl;
// std::cout << b.getRawBits() << std::endl;
// std::cout << c.getRawBits() << std::endl;

Fixed   a(6.6f);
// float param = 3.645;

// float x = 3.1;
// int   y = 4;


std::cout << a << std::endl;
// std::cout << y << std::endl;


// int fixed_point;
// // const int n_fractional_bits = 8;


// // fixed_point = param << n_fractional_bits;

// // std::cout << fixed_point << std::endl;

// // fixed_point = fixed_point >> n_fractional_bits;
// // std::cout << fixed_point << std::endl;


// fixed_point = param * 256 ;

// std::cout << fixed_point << std::endl;

// fixed_point = fixed_point / (float)256;
// std::cout << fixed_point << std::endl;

return 0;
}