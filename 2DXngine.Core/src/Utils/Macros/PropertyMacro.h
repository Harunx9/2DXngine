#pragma once

#define PROPERTY(type, name)        \
private:                            \
    type _##name;                   \
                                    \
public:                             \
inline type get_##name() const      \
{                                   \
    return this->_##name;           \
}                                   \
                                    \
inline void set_##name(type value)  \
{                                   \
    this->_##name  = value;         \
}

#define READONLY_PROPERTY(type, name)\
private:                             \
    type _##name;                    \
                                     \
public:                              \
inline type get_##name() const       \
{                                    \
    return this->_##name;            \
}

#define NOTIFY_PROPERTY(type, name, handler)\
private:                                    \
    type _##name;                           \
                                            \
public:                                     \
inline type get_##name() const              \
{                                           \
    return this->_##name;                   \
}                                           \
                                            \
inline void set_##name(type value)          \
{                                           \
    if(this->_##name  != value)             \
    {                                       \
        this->_##name = value;              \
        auto tmp = handler;                 \
        if(tmp.isUsed())                    \
        {                                   \
            tmp(EventArgs());               \
        }                                   \
    }                                       \
                                            \
}