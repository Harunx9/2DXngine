#include "Service.h"


Service::Service(const char * name): 
    _name(name)
{
}

Service::~Service()
{
}

std::string Service::get_name() const
{
    return this->_name;
}