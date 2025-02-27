#include "Point.hpp"



Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}

Point& Point::operator=(const Point& obj)
{
   if (this != &obj)
        std::cout << "Can not assign the object !" << std::endl;
    return (*this);
}

Point::~Point()
{
}

const Fixed Point::get_x() const
{
    return (this->x);
}
const Fixed Point::get_y() const
{
    return (this->y);
}