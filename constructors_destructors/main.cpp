#include <iostream>

class Entity {
  public:
    float X, Y;
    
    Entity() {
      X = 0.0f;
      Y = 0.0f;
      std::cout << "constructor" << std::endl;
    }
    
    ~Entity() {
      std::cout << "destructor" << std::endl;
    }
    
    void Print() {
      std::cout << X << ", " << Y << std::endl;
    }
};

void Function() {
  Entity e;
  e.Print();
}

int main() {
  Entity e;
  e.Print();
  std::cin.get();
}