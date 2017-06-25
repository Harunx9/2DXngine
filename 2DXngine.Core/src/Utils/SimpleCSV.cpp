#include "SimpleCSV.h"
#include <sstream>
#include <fstream>
#include "StringUtils.h"
SimpleCSV::SimpleCSV(char separator):
    _separator(separator)
{
}

SimpleCSV::~SimpleCSV()
{
}

csv_content SimpleCSV::parseFile(std::string filename)
{
    std::string line;
    csv_content content;
    std::ifstream infile(filename);
    int lineNumber = 0;

    while (std::getline(infile, line))
    {
        line = trim(line);
        csv_line parsedLine = this->parseLine(line);
        content.push_back(parsedLine);
    }
    return content;
}

csv_line SimpleCSV::parseLine(std::string line)
{
    std::istringstream iss(line);
    std::string str;
    csv_line parsedLine;
    while (std::getline(iss, str, this->_separator))
    {
        str = trim(str);
        parsedLine.push_back(str);
    }
    return parsedLine;
}

csv_content SimpleCSV::parseText(std::string text)
{
    std::istringstream iss(text);
    csv_content content;
    std::string line;
    while (std::getline(iss, line))
    {
        csv_line parsedLine = this->parseLine(line);
        content.push_back(parsedLine);
    }
    return content;
}
