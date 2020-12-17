#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

int dimension_require (std::string& str);
int min_sum (std::vector<int>& in);
int ribbon_require (std::string& in);
std::vector<std::string> read_line(std::ifstream& file);


int main ()
{
    int square = 0;
    int ribbon = 0;
    std::ifstream myfile("../input.txt", std::fstream::in);
    if (!myfile.is_open())
    {
        std::cout << "Error for load File" << std::endl;
        return -1;
    }

    for (auto item : read_line(myfile) ) 
    {
        square = square + dimension_require(item);      
        ribbon = ribbon + ribbon_require(item);  
    }

    std::cout << "Squere require:  " << square << std::endl;    
    std::cout << "Ribbon require:  " << ribbon << std::endl;    

    return 1;
}

int dimension_require (std::string& str)
{
    int result = 0;
    std::vector<int> out;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, 'x'))
    {
        out.push_back(std::stoi(token));
    }
    
    result = 2 * out[0] * out[1] + 2 * out[1] * out[2] + 2 * out[2] * out[0] + min_sum(out);     

    return result;
}

std::vector<std::string> read_line (std::ifstream& file)
{
    std::vector<std::string> out;
    std::string item = "";
    while (std::getline(file, item))
    {
        out.push_back(item);
    }
    
    return out;
}

int min_sum (std::vector<int>& input)
{
    std::sort(input.begin(), input.end());
    return input[0] * input[1];
}


int ribbon_require (std::string& str)
{
    int result = 0;
    std::vector<int> out;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, 'x'))
    {
        out.push_back(std::stoi(token));
    }
    std::sort(out.begin(), out.end());
    
    result = 2 * out[0] + 2 * out[1] + out[0] * out[1] * out[2];     

    return result;
}

