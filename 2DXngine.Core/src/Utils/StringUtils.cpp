#include "StringUtils.h"
#include <algorithm>
#include <locale>

std::string trimL(std::string& in)
{
    auto it2 = std::find_if(in.begin(), in.end(), [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
    in.erase(in.begin(), it2);
    return in;
}

std::string trimR(std::string& in)
{
    auto it1 = std::find_if(in.rbegin(), in.rend(), [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
    in.erase(it1.base(), in.end());
    return in;
}

std::string trim(std::string& in)
{
    trimR(in);
    trimL(in);
    return in;
}
