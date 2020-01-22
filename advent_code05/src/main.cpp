#include <iostream>
#include <fstream>
#include <string>


bool have_vowels(std::string &str);

int main()
{
    std::ifstream myFile("../input.txt", std::fstream::in);
    if (!myFile.is_open())
    {
        std::cout << "Error load file" << std::endl;
        return -1;
    }
    std::string _string((std::istreambuf_iterator<char>(myFile)), std::istreambuf_iterator<char>());

    std::string test = "ugknbfddgicrmopn";
    std::cout << have_vowels(test) << std::endl;

    return 1;
}

bool have_vowels(std::string &str)
{
    char vowel = ' ';
    bool bool_out = false;
    int a = 0, e = 0, i =0, o = 0, u = 0, out = 0;
    for (int i = 0; i < str.length(); i++)
    {
        vowel = str[i];
        switch (vowel)
        {
        case 'a':
            a++;
            break;
        case 'e':
            e++;
            break;
        case 'i':
            i++;
            break;
        case 'o':
            o++;
            break;
        case 'u':
            u++;
            break;
        default:
            break;
        }
    }
    out = a + e + i + o + u;
    if(out > 0)
        bool_out = true;
    return bool_out;
}
