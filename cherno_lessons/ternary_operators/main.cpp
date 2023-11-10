#include <iostream>

static int Level = 1;
static int Speed = 2;

int main() {
  
  if (Level > 5)
    Speed = 10;
  else
    Speed = 5;
  
  Speed = Level > 5 ? 10 : 5;
  
  std::cin.get();
}