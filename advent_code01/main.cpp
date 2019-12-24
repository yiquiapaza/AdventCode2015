#include <iostream>
#include <fstream>
#include <string>

int main() 
{    
    int result = 0;
    std::ifstream myfile("../input.txt",std::fstream::in);
    if (!myfile.is_open())
    {
        std::cout << "Error for load File" << std::endl;        
        return -1;
    }
    std::string _string((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());

    for(char& a :_string)
    {
        (a == '(') ? result++ : result--;
    }    
    std::cout << result << std::endl;

    return 0;
}
