#pragma once
#include <string>
#include <vector>
namespace stringutils {

    static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    std::string trimL(std::string& in);
    std::string trimR(std::string& in);
    std::string trim(std::string& in);
    std::vector<std::string> split(std::string& input, char delimiter);
    std::string replaceAll(std::string& input, std::string& from, std::string& to);
    //Implemenatation from 
    //http://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp
    bool is_base64(unsigned char c);
    std::string Base64decode(std::string& input);
    std::string Base64encode(std::string& input);
}


