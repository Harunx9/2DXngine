#pragma once

class Point
{
public:
    Point();
    Point(int x, int y);
    ~Point();

    int get_x() const;
    void set_x(int x);
    int get_y() const;
    void set_y(int y);
private:
    int _x, _y;
};

