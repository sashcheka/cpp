#include <iostream>
#include <string>

int main() {
  std::string j, s;
  
  std::cin >> j;
  std::cin >> s;
  
  int i = 0;
  
  for (char& ch : s) {
    if(j.find(ch) != std::string::npos)
      i++;
  }
  
  std::cout << i;
}