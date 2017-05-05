#pragma once

#define PROPERTY(type, name)        \
private:                            \
    type _##name;                    \
                                    \
public:                             \
inline type get_##name()             \
{                                   \
    return this->_##name;            \
}                                   \
                                    \
inline void set_##name(type value)   \
{                                   \
    this->_##name  = value;          \
}
