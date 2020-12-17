#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

bool vowels(std::string &str);
bool not_contain(std::string &str);
bool twice(std::string &str);
std::vector<std::string> read_line(std::ifstream &file);

int main()
{
  std::ifstream myFile("../input.txt", std::fstream::in);
  int result = 0; 
  if (!myFile.is_open())
  {
    std::cout << "Error load file" << std::endl;
    return -1;
  }
/*   std::string _string((std::istreambuf_iterator<char>(myFile)), std::istreambuf_iterator<char>());
 */

  for (std::string item : read_line(myFile))
  {
    if( vowels(item) && twice(item) && not_contain(item))
    {
      std::cout << item << std::endl;
      std::cout << "Vowels Test: " << vowels(item) << std::endl;
      std::cout << "Twice letter: " << twice(item) << std::endl;
      std::cout << "Not contain word: " << not_contain(item) << std::endl;
      std::cout << "@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
      result++;
    }    
  }    
  std::cout << result << std::endl;
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
  for(int i = 0; str.length() > i ; i++)
  {
    if(str[i] == str[i+1])
    {
      tmp = true;
      break;
    }
  }
  return tmp;
}

std::vector<std::string> read_line(std::ifstream &file)
{
  std::vector<std::string> out;
  std::string item = "";
  while (std::getline(file,item))
  {
    out.push_back(item);
  }
  return out;
}
