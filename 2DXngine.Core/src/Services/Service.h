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
    std::string get_Name() const;
protected:
    std::string _name;
};

