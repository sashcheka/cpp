#include "newBlockchain.h"
#include <iostream>

int main() {
  Singleton& instance1 = Singleton::Get();
  Singleton& instance2 = Singleton::Get();
  Singleton& instance3 = Singleton::Get();
  Singleton& instance4 = Singleton::Get();
  Singleton& instance5 = Singleton::Get();
  

  if (&instance1 == &instance2) {
    std::cout << "Both instances are the same (Singleton works)." << std::endl;
  } else {
    std::cout << "Instances are different (Singleton does not work)." << std::endl;
  }

  return 0;
}
