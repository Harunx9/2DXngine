#include "ServiceLocator.h"

service_map ServiceLocator::_services;

void ServiceLocator::initialize()
{
    for(auto it = _services.rbegin(); it != _services.rend(); ++it)
        it->second->initialize();
}
