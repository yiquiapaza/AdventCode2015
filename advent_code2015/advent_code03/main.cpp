#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

int main ()
{
    std::ifstream myFile("../input.txt", std::fstream::in);

    std::string str ((std::istream_iterator<char>(myFile)),  (std::istream_iterator<char>()) );

    std::map<std::pair<int,int>, bool> m;

    std::pair<int,int> p;
    p.first = 0;
    p.second = 0;
    m[p] = true;
    int acumulator = 1;
    
    for (char i : str)
    {    
        switch (i)
        {
        case '>':
            p.first++;
            break;
        case '<':
            p.first--;
            break;
        case '^':
            p.second++;
            break;
        case 'v':
            p.second--;
            break;
        }
        if (m.count(p) == 0)
        {
            acumulator++;
            m[p] = true;
        }
        
    }
    
    std::cout << acumulator << std::endl;
    return 1;
}