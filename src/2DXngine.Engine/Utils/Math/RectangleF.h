#pragma once
#include <glm/vec2.hpp>

class RectangleF
{
public:
    RectangleF(float x, float y, float width, float height);
    ~RectangleF();

    float get_x() const;
    float get_y() const;
    void set_x(float x);
    void set_y(float y);

    float get_width() const;
    float get_height() const;
    void set_width(float width);
    void set_height(float height);

    glm::vec2 get_position() const;

    float get_top() const;
    float get_bottom() const;
    float get_left() const;
    float get_right() const;

    bool intersect(const RectangleF& other);
    bool insersect(const RectangleF* other);
    bool contains(float x, float y);
private:
    float _x, _y;
    float _width, _heihgt;
};
