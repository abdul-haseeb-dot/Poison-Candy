#include "Utils.hpp"
#include<sstream>

std::vector<std::string> SplitLines(const std::string &str)
{
    std::vector<std::string> lines;
    std::stringstream ss(str);
    std::string line;
    while(getline(ss,line))
    {
        lines.push_back(line);
    }
    return lines;
}