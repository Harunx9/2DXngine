#include "RectangleF.h"

RectangleF::RectangleF(float x, float y, float width, float height) :
    _x(x),
    _y(y),
    _width(width),
    _heihgt(height)
{
}

RectangleF::~RectangleF()
{
}

float RectangleF::get_x() const
{
    return this->_x;
}

float RectangleF::get_y() const
{
    return this->_y;
}

void RectangleF::set_x(float x)
{
    this->_x = x;
}

void RectangleF::set_y(float y)
{
    this->_y = y;
}

float RectangleF::get_width() const
{
    return this->_width;
}

float RectangleF::get_height() const
{
    return this->_heihgt;
}

void RectangleF::set_width(float width)
{
    this->_width = width;
}

void RectangleF::set_height(float height)
{
    this->_heihgt = height;
}

glm::vec2 RectangleF::get_position() const
{
    return glm::vec2(this->_x, this->_y);
}

float RectangleF::get_top() const
{
    return this->_y;
}

float RectangleF::get_bottom() const
{
    return this->_y + this->_heihgt;
}

float RectangleF::get_left() const
{
    return this->_x;
}

float RectangleF::get_right() const
{
    return this->_x + this->_width;
}

bool RectangleF::intersect(const RectangleF & other)
{
    return (other.get_left() <= this->get_right()) ||
        (other.get_right() >= this->get_right()) ||
        (other.get_top() <= this->get_bottom()) ||
        (other.get_bottom() >= this->get_top());
}

bool RectangleF::insersect(const RectangleF * other)
{
    return (other->get_left() <= this->get_right()) ||
        (other->get_right() >= this->get_right()) ||
        (other->get_top() <= this->get_bottom()) ||
        (other->get_bottom() >= this->get_top());
}