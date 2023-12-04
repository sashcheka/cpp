#include <iostream>

void Func() {
  static int i = 0;
  i++;
  std::cout << i << std::endl;
}

int main() {
  Func();
  Func();
  Func();
  std::cin.get();
}