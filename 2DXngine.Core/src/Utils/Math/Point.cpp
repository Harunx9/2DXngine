#include "Point.h"

Point::Point() :
    _x(0),
    _y(0)
{
}

Point::Point(int x, int y) :
    _x(x),
    _y(y)
{
}

Point::~Point()
{
}

int Point::get_x() const
{
    return this->_x;
}

void Point::set_x(int x)
{
    this->_x = x;
}

int Point::get_y() const
{
    return this->_y;
}

void Point::set_y(int y)
{
    this->_y = y;
}
