#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

bool vowels(std::string &str);
bool not_contain(std::string &str);
bool twice(std::string &str);

int main()
{
  std::ifstream myFile("../input.txt", std::fstream::in);
  if (!myFile.is_open())
  {
    std::cout << "Error load file" << std::endl;
    return -1;
  }
  std::string _string((std::istreambuf_iterator<char>(myFile)), std::istreambuf_iterator<char>());

  std::string test = "jchzalrnumimnmhp";

  std::cout << vowels(test) << std::endl;
  std::cout << twice(test) << std::endl;
  std::cout << not_contain(test) << std::endl;
  
  /* std::cout << _string << std::endl; */

  return 0;
}

bool vowels(std::string &str)
{
  int count = 0;
  count += std::count(str.begin(), str.end() ,'a');
  count += std::count(str.begin(), str.end(), 'e');
  count += std::count(str.begin(), str.end(), 'i');
  count += std::count(str.begin(), str.end(), 'o');
  count += std::count(str.begin(), str.end(), 'u');
  if ( count > 2 )
    return true;
  else 
    return false;
}

bool not_contain(std::string &str)
{
  if( (str.find("ab") != std::string::npos) || (str.find("cd") != std::string::npos) || (str.find("pq") != std::string::npos) || (str.find("xy") != std::string::npos ) )
    return false;
  else 
    return true;
}

bool twice(std::string &str)
{
  bool tmp = false;
  for(char& c:str)
  {
    if(str.find(c+c) != std::string::npos)
    {
      tmp = true;
      break;
    }
  }
  return tmp;
}
