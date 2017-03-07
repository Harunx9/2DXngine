#include "Service.h"


Service::Service(const char * name): 
    _name(name)
{
}

Service::~Service()
{
}

std::string Service::get_Name() const
{
    return this->_name;
}