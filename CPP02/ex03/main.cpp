#include <iostream>
#include <math.h>
#include "Point.hpp"
#include <iostream>


int main( void )
{
    Point a, b(10, 30) ,c(20, 0), point(10, 15);

    if (bsp(a, b, c, point))
        std::cout << "point inside\n";
    else
        std::cout << "point is out\n";
}