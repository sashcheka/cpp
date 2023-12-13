#include <iostream>
#include <fstream>

int main() 
{
  std::ifstream iFile("input.txt");
  int a, b;
  iFile >> a >> b;
  iFile.close();
  
  std::ofstream oFile("output.txt");
  oFile << a + b;
  oFile.close();
}