#include "Path.h"
#include "StringUtils.h"

std::string Path::normalize(std::string input)
{
    #if WIN32
    std::string from = "/";
    std::string to = "\\";
    return stringutils::replaceAll(input, from, to);
    #else
    std::string from = "\\";
    std::string to = "/";
    return stringutils::replaceAll(input, from, to);
    #endif
}
