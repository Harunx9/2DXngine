#pragma once
#include <string>
#include <map>
#include "Service.h"

typedef std::map<std::string, Service*> service_map;

class ServiceLocator
{
public:
    ServiceLocator() = delete;
    ServiceLocator(const ServiceLocator * other) = delete;
    virtual ~ServiceLocator() = delete;

    template<class TService>
    static TService* get(const char * name);

    template<class TService>
    static void registerService(const TService* service);
private:
    static service_map _services;
};

template<class TService>
static inline TService* ServiceLocator::get(const char * name)
{
    auto srv = _services.at(serviceName);
    return (TService *)srv;
}

template<class TService>
static inline void ServiceLocator::registerService(const TService * service)
{
    Service* tmp = (Service*)service;
    _services[tmp->get_Name()] = tmp;
}