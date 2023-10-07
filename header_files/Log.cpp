#include <iostream>
#include "Log.h"

void InitLog() {
  Log("Log");
}

void Log(const char* mes) {
  std::cout << mes << std::endl;
}