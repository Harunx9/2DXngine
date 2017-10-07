#include "PointI.h"

PointI::PointI() :
    _x(0),
    _y(0)
{
}

PointI::PointI(int x, int y) :
    _x(x),
    _y(y)
{
}

PointI::~PointI()
{
}

int PointI::get_x() const
{
    return this->_x;
}

void PointI::set_x(int x)
{
    this->_x = x;
}

int PointI::get_y() const
{
    return this->_y;
}

void PointI::set_y(int y)
{
    this->_y = y;
}
