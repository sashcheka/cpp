#include <iostream>
#include <string>
#include <cstring>

int main() {
  using namespace std::string_literals;
  std::string name0 = "Arstiom"s + " Sashcheka";
  
  const char* name = u8"Artsiom";
  const wchar_t* name2 = L"Artsiom";
  
  const char16_t* name3 = u"Arstiom";
  const char32_t* name4 = U"Artsiom";
  
  std::cout << name << std::endl;
  std::cin.get();
}