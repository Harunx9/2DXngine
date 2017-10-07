#pragma once

class PointI
{
public:
    PointI();
    PointI(int x, int y);
    ~PointI();

    int get_x() const;
    void set_x(int x);
    int get_y() const;
    void set_y(int y);
private:
    int _x, _y;
};

