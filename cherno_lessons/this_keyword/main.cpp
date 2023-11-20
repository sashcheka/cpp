#include <iostream>

class Entity {
public:
  int x, y;

  Entity(int x, int y) {
    (*this).x = x;
    this->y = y;

    Entity& e = *this;

    PrintEntity(*this);

    delete this;
  }
  
  int GetX() const {
    const Entity& e = *this;
    return this->x;
  }

  void PrintEntity(const Entity& e);
};

int main() {
  
  std::cin.get();
}