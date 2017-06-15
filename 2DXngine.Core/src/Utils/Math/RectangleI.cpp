#include "RectangleI.h"

RectangleI::RectangleI():
    _x(0),
    _y(0),
    _width(0),
    _heihgt(0)
{
}

RectangleI::RectangleI(int x, int y, int width, int height) :
    _x(x),
    _y(y),
    _width(width),
    _heihgt(height)
{
}

RectangleI::~RectangleI()
{
}

int RectangleI::get_x() const
{
    return this->_x;
}

int RectangleI::get_y() const
{
    return this->_y;
}

void RectangleI::set_x(int x)
{
    this->_x = x;
}

void RectangleI::set_y(int y)
{
    this->_y = y;
}

int RectangleI::get_width() const
{
    return this->_width;
}

int RectangleI::get_height() const
{
    return this->_heihgt;
}

void RectangleI::set_width(int width)
{
    this->_width = width;
}

void RectangleI::set_height(int height)
{
    this->_heihgt = height;
}

PointI RectangleI::get_position() const
{
    return PointI(this->_x, this->_y);
}

int RectangleI::get_top() const
{
    return this->_y;
}

int RectangleI::get_bottom() const
{
    return this->_y + this->_heihgt;
}

int RectangleI::get_left() const
{
    return this->_x;
}

int RectangleI::get_right() const
{
    return this->_x + this->_width;
}

bool RectangleI::intersect(const RectangleI & other)
{
    return (other.get_left() <= this->get_right()) ||
        (other.get_right() >= this->get_right()) ||
        (other.get_top() <= this->get_bottom()) ||
        (other.get_bottom() >= this->get_top());
}

bool RectangleI::insersect(const RectangleI * other)
{
    return (other->get_left() <= this->get_right()) ||
        (other->get_right() >= this->get_right()) ||
        (other->get_top() <= this->get_bottom()) ||
        (other->get_bottom() >= this->get_top());
}
