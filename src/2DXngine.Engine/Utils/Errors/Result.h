#pragma once
#include <string>
#include <vector>
#include "../Macros/PropertyMacro.h"

struct Error
{
    void* issuer;
    std::string message;
};

class Result
{
public:
    Result();
    virtual ~Result();

    inline bool isValid()
    {
        return this->_errors.empty();
    }

    void  addError(Error error);
    READONLY_PROPERTY(std::vector<Error>, errors)
};

template<class TModel>
class TResult: public Result
{
    TResult();
    ~TResult();

    PROPERTY(TModel, model)
};

template<class TModel>
inline TResult<TModel>::TResult() : Result()
{
}

template<class TModel>
inline TResult<TModel>::~TResult()
{
}
