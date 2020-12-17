#include <md5.h>

int main()
{
    std::string input = "yzbqklnj", hash = "";
    std::string zeroString(5,'0');
    int guess = -1;
    do
    {
        guess++;
        hash = md5(input + std::to_string(guess));
    } while (hash.substr(0,5) != zeroString);
    
    std::cout << input + std::to_string(guess);

    return 1;
}