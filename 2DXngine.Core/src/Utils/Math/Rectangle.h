#include "Point.h"
#pragma once


class Rectangle
{
public:
    Rectangle(int x, int y, int width, int height);
    ~Rectangle();

    int get_x() const;
    int get_y() const;
    void set_x(int x);
    void set_y(int y);

    int get_width() const;
    int get_height() const;
    void set_width(int width);
    void set_height(int height);

    Point get_position() const;

    int get_top() const;
    int get_bottom() const;
    int get_left() const;
    int get_right() const;

    bool intersect(const Rectangle& other);
    bool insersect(const Rectangle* other);
private:
    int _x, _y;
    int _width, _heihgt;
};

