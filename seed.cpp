#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <cstring>
#include <unordered_map>



std::string revcomp(std::string s)
{
    // get reversed complementary sequence
    std::string temp_str;
    std::reverse(s.begin(), s.end());

    for (unsigned long i = 0; i < s.length(); i++)
    {
        if (s.substr(i, 1) == "A" || s.substr(i, 1) == "a")
        {
            temp_str += "T";
        }
        else if (s.substr(i, 1) == "T" || s.substr(i, 1) == "t")
        {
            temp_str += "A";
        }
        else if (s.substr(i, 1) == "C" || s.substr(i, 1) == "c")
        {
            temp_str += "G";
        }
        else if (s.substr(i, 1) == "G" || s.substr(i, 1) == "g")
        {
            temp_str += "C";
        }
        else
        {
            temp_str += "N";
        }
    }
    s = temp_str;
    return s;
}