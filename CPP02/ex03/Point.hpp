#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"


class Point
{
    private:
    Fixed const x;
    Fixed const y;
    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &obj);
        Point& operator=(const Point& obj);
        ~Point();
        const Fixed get_x() const;
        const Fixed get_y() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
