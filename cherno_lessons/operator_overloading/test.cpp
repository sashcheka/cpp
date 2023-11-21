#include <iostream>

class Entity {
  public:
    int x;
};

std::ostream& operator<<(std::ostream& stream, const Entity& other) {
  stream << other.x << std::endl;
  return stream;
}

std::istream& operator>>(std::istream& stream, Entity& other) {
  stream >> other.x;
  return stream;
}

int main() {
  Entity e;
  e.x = 2;
  
  std::cout << e;
  operator<<(std::cout, e);
  operator>>(std::cin, e);
}