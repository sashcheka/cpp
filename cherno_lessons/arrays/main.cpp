#include <iostream>

class Entity {
  public:
    static const int exampleSize = 5;
    int example[exampleSize];
    Entity() {
      for (int i = 0; i < exampleSize; i++) {
          example[i] = 2;
      }
    }
};

int main() {
  Entity e;
  
  std::cin.get();
}


//int array[n] vs int array = new int[n];