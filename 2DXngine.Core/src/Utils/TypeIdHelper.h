#pragma once

typedef size_t TypeId;

template<typename TImplmementation>
class TypeIdInfo
{
public:
    template <typename TImplmementation>
    static TypeId GetTypeId()
    {
        static const TypeId id = _nextTypeId++;
        return id;
    }

private:
    static TypeId _nextTypeId;
};

template<typename TImplementation>
TypeId TypeIdInfo<TImplementation>::_nextTypeId = 0;
