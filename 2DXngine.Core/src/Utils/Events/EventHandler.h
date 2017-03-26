#pragma once
#include <functional>
#include <map>
#include <algorithm>
#include "EventArgs.h"



#define CREATE_BINDING(Id, Type, Handler) \
Binding<EventArgs>(Id, std::bind(&Type::Handler, this, std::placeholders::_1));

#define CREATE_BINDING_WITH_PARAM(Id, Type, Handler, ParamType) \
Binding<ParamType>(Id, std::bind(&Type::Handler, this, std::placeholders::_1));

template<typename TEventArgs>
struct Binding
{
    Binding() {}
    Binding(int code, std::function<void(TEventArgs)> func)
    {
        this->_code = code;
        this->_func = func;
    }

    int get_code() const { return this->_code; }
    std::function<void(TEventArgs)> get_func() const { return this->_func; }

private:
    int _code;
    std::function<void(TEventArgs)> _func;
};

class EventHandler
{
public:
    EventHandler& operator+=(Binding<EventArgs> binding)
    {
        _subscribers[binding.get_code()] = binding.get_func();
        return *this;
    }

    EventHandler& operator-=(Binding<EventArgs> binding)
    {
        _subscribers.erase(binding.get_code());
        return *this;
    }

    bool isUsed() { return _subscribers.empty() == false; }

    void invoke(EventArgs args)
    {
        auto tmp = this->_subscribers;
        for (auto& subscriber : tmp)
        {
            subscriber.second(args);
        }
    }

    void operator()(EventArgs args)
    {
        this->invoke(args);
    }

    inline static int get_nextID()
    {
        return _curretnId++;
    }
private:
    static int _curretnId;
    std::map<int, std::function<void(EventArgs)>> _subscribers;
};

template<typename TEventArgs>
class EventParameterHandler
{
public:
    EventParameterHandler& operator+=(Binding<TEventArgs> binding)
    {
        _subscribers[binding.get_code()] = binding.get_func();
        return *this;
    }

    EventParameterHandler& operator-=(Binding<TEventArgs> binding)
    {
        _subscribers.erase(binding.get_code());
        return *this;
    }

    bool isUsed() { return _subscribers.empty() == false; }

    void invoke(TEventArgs args)
    {
        auto tmp = this->_subscribers;
        for (auto& subscriber : tmp)
        {
            subscriber.second(args);
        }
    }

    void operator()(TEventArgs args)
    {
        this->invoke(args);
    }

    static int get_nextID();
private:
    static int _curretnId;
    std::map<int, std::function<void(TEventArgs)>> _subscribers;
};

template<typename TEventArgs>
inline int EventParameterHandler<TEventArgs>::get_nextID()
{
    return EventParameterHandler<TEventArgs>::_curretnId++;
}
template<typename TEventArgs>
int EventParameterHandler<TEventArgs>::_curretnId = 0;