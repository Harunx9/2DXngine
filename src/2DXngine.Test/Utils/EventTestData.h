#pragma once

#include "EventTestData.h"
#include <Utils\Events\EventHandler.h>

class TestParameterlessPublisher
{
public:
    TestParameterlessPublisher() {}
    ~TestParameterlessPublisher() {}
    EventHandler handler;
    void trigger()
    {
        auto tmpHandler = handler;
        if (tmpHandler.isUsed())
        {
            tmpHandler(EventArgs());
        }
    }

};

class TestParameterlessSubscriber
{
public:
    TestParameterlessSubscriber(TestParameterlessPublisher* publiser)
    {
        counter = 0;
        _publiser = publiser;
        _binding = CREATE_BINDING(EventHandler::get_nextID(), TestParameterlessSubscriber, handle);
        publiser->handler += _binding;
    }

    ~TestParameterlessSubscriber() {}

    int counter;

    void clearUnsubscribe()
    {
        _publiser->handler -= _binding;
    }

    void handle(EventArgs args)
    {
        counter += 1;
    }

private:
    Binding<EventArgs> _binding;
    TestParameterlessPublisher* _publiser;
};

class TestParameterlessSubscriberWithList
{
public:
    TestParameterlessSubscriberWithList()
    {
        counter = 0;
        _binding = CREATE_BINDING(EventHandler::get_nextID(), TestParameterlessSubscriberWithList, handle)
    }

    ~TestParameterlessSubscriberWithList() {}

    int counter;

    void addPublisher(TestParameterlessPublisher* publiser)
    {
        publiser->handler += _binding;
        this->_publishers.push_back(publiser);
    }

    void clearUnsubscribe()
    {
        for (auto& publisher : this->_publishers)
            publisher->handler -= _binding;

        this->_publishers.clear();
    }

    void handle(EventArgs args)
    {
        counter += 1;
    }

private:
    Binding<EventArgs> _binding;
    std::vector<TestParameterlessPublisher*> _publishers;
};

class NameEventArgs : public EventArgs
{
public:
    NameEventArgs(std::string name)
    {
        _name = name;
    }

    ~NameEventArgs()
    {
    }

    std::string get_name() const { return this->_name; }

private:
    std::string _name;
};


class TestParameterPublisher
{
public:
    TestParameterPublisher() {}
    ~TestParameterPublisher() {}
    EventParameterHandler<NameEventArgs> handler;
    void trigger()
    {
        auto tmpHandler = handler;
        if (tmpHandler.isUsed())
        {
            tmpHandler(NameEventArgs("Test"));
        }
    }

};

class TestParameterSubscriber
{
public:
    TestParameterSubscriber(TestParameterPublisher* publiser)
    {
        _publiser = publiser;
        _binding = CREATE_BINDING_WITH_PARAM(EventParameterHandler<NameEventArgs>::get_nextID(), TestParameterSubscriber, handle, NameEventArgs);
        publiser->handler += _binding;
    }

    ~TestParameterSubscriber() {}

    std::string name;

    void clearUnsubscribe()
    {
        _publiser->handler -= _binding;
    }

    void handle(NameEventArgs args)
    {
        name = args.get_name();
    }

private:
    Binding<NameEventArgs> _binding;
    TestParameterPublisher* _publiser;
};

class TestParameterSubscriberWithList
{
public:
    TestParameterSubscriberWithList()
    {
        _binding = CREATE_BINDING_WITH_PARAM(EventParameterHandler<NameEventArgs>::get_nextID(), TestParameterSubscriberWithList, handle, NameEventArgs);
    }

    ~TestParameterSubscriberWithList() {}

    std::vector<std::string> names;

    void addPublisher(TestParameterPublisher* publiser)
    {
        publiser->handler += _binding;
        this->_publishers.push_back(publiser);
    }

    void clearUnsubscribe()
    {
        for (auto& publisher : this->_publishers)
            publisher->handler -= _binding;

        this->_publishers.clear();
    }

    void handle(NameEventArgs args)
    {
        names.push_back(args.get_name() + "_" + std::to_string(names.size() + 1));
    }

private:
    Binding<NameEventArgs> _binding;
    std::vector<TestParameterPublisher*> _publishers;
};