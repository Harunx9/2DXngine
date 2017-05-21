#pragma once
#include <string>

class Service
{
public:
    Service(const char* name);
    Service(const Service* other) = delete;
    virtual ~Service();

    virtual void initialize() = 0;
    virtual void terminate() = 0;
    std::string get_name() const
    {
        return this->_name;
    }

    inline bool get_isInitialized() const
    {
        return this->_isInitialized;
    }

    inline bool get_isTerminated() const
    {
        return this->_isTerminated;
    }

protected:
    std::string _name;
    bool _isInitialized;
    bool _isTerminated;
};

