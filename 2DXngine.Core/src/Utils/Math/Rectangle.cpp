#include "Rectangle.h"

Rectangle::Rectangle():
    _x(0),
    _y(0),
    _width(0),
    _heihgt(0)
{
}

Rectangle::Rectangle(int x, int y, int width, int height) :
    _x(x),
    _y(y),
    _width(width),
    _heihgt(height)
{
}

Rectangle::~Rectangle()
{
}

int Rectangle::get_x() const
{
    return this->_x;
}

int Rectangle::get_y() const
{
    return this->_y;
}

void Rectangle::set_x(int x)
{
    this->_x = x;
}

void Rectangle::set_y(int y)
{
    this->_y = y;
}

int Rectangle::get_width() const
{
    return this->_width;
}

int Rectangle::get_height() const
{
    return this->_heihgt;
}

void Rectangle::set_width(int width)
{
    this->_width = width;
}

void Rectangle::set_height(int height)
{
    this->_heihgt = height;
}

Point Rectangle::get_position() const
{
    return Point(this->_x, this->_y);
}

int Rectangle::get_top() const
{
    return this->_y;
}

int Rectangle::get_bottom() const
{
    return this->_y + this->_heihgt;
}

int Rectangle::get_left() const
{
    return this->_x;
}

int Rectangle::get_right() const
{
    return this->_x + this->_width;
}

bool Rectangle::intersect(const Rectangle & other)
{
    return (other.get_left() <= this->get_right()) ||
        (other.get_right() >= this->get_right()) ||
        (other.get_top() <= this->get_bottom()) ||
        (other.get_bottom() >= this->get_top());
}

bool Rectangle::insersect(const Rectangle * other)
{
    return (other->get_left() <= this->get_right()) ||
        (other->get_right() >= this->get_right()) ||
        (other->get_top() <= this->get_bottom()) ||
        (other->get_bottom() >= this->get_top());
}
