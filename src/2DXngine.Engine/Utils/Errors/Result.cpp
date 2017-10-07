#include "Result.h"



Result::Result()
{
    this->_errors = std::vector<Error>();
}


Result::~Result()
{
}

void Result::addError(Error error)
{
    this->_errors.push_back(error);
}
