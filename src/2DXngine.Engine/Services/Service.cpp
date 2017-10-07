#include "Service.h"


Service::Service(const char * name): 
    _name(name),
    _isInitialized(false),
    _isTerminated(false)
{
}

Service::~Service()
{
}

void Service::baseInitialize()
{
    if (this->_isInitialized) return;
    
    this->initialize();

    this->_isInitialized = true;
}

void Service::baseTerminate()
{
    if (this->_isTerminated) return;

    this->terminate();

    this->_isTerminated = true;
}
