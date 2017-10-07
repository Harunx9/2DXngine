#pragma once
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> csv_line;
typedef std::vector<csv_line> csv_content;

class SimpleCSV
{
public:
    SimpleCSV(char separator);
    ~SimpleCSV();

    csv_content parseFile(std::string filename);
    csv_line parseLine(std::string line);
    csv_content parseText(std::string text);
private:
    char _separator;
};

