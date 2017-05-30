#include "Service.h"


Service::Service(const char * name): 
    _name(name),
    _isInitialized(false),
    _isTerminated(false)
{
}

Service::~Service()
{
    this->terminate();
}
