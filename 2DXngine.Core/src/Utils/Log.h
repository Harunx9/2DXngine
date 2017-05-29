#pragma once
#include <iostream>
#include <chrono>


#define log(Type, Message)                                                            \
std::cout<< #Type << " " << Message << std::endl