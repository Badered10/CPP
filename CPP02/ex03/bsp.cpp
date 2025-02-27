#include "Point.hpp"

float area(Point const a, Point const b, Point const c)
{
    float res;

    res = (
    ( a.get_x().getRawBits() * (b.get_y().getRawBits() - c.get_y().getRawBits()) 
    + b.get_x().getRawBits() * (c.get_y().getRawBits() - a.get_y().getRawBits()) 
    + c.get_x().getRawBits() * (a.get_y().getRawBits() - b.get_y().getRawBits()) ) 
    / 2.0);
;
    if (res < 0)
        res *=-1;
    return (res);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float ABC, ABP, ACP, CBP;

    ABC = area(a, b, c);
    ABP = area(a, b, point);
    ACP = area(a, c, point);
    CBP = area(c, b, point);

    if (!ABP || !ACP || !CBP)
        return (false);
    if ((ABP + ACP + CBP) == ABC)
        return (true);
    return (false);
}
