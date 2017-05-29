#include "ServiceLocator.h"

service_map ServiceLocator::_services;

void ServiceLocator::terminate()
{
    for (auto& service : _services)
    {
        service.second->terminate();
    }
}
