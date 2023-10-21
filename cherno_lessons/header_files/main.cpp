#include <iostream>
#include "Log.h"

int main() {
  InitLog();
  Log("main");
  std::cin.get();
}