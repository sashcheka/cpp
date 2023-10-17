#include <cstddef>
#include <iostream>
#include <string>


void PrintString(std::string& string) {
  string += "SSS";
  std::cout << string << std::endl;
}

int main() {
  std::string name = std::string("artsiom") + " sashcheka";
  
  bool contains = name.find("ch") != std::string::npos;
  
  std::cout << contains << std::endl;
  std::cout << name << std::endl;
  PrintString(name);
  std::cout << name << std::endl;
  
  
  std::cin.get();
}