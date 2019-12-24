#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

std::vector<int> dimension_require (std::string& str);

int main ()
{
    std::ifstream myfile("../input.txt", std::fstream::in);
    if (!myfile.is_open())
    {
        std::cout << "Error for load File" << std::endl;
        return -1;
    }

    std::string out = "2x3x4";
    std::vector<int> list;
    list = dimension_require(out);
    for (auto item : list)
    {
        std::cout << item << std::endl;
    }
    

    return 1;
}

std::vector<int> dimension_require (std::string& str)
{
    std::vector<int> out;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, 'x'))
    {
        out.push_back(std::stoi(token));
    }
    
    return out;
}