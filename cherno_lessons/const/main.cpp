#include <iostream>

class Entity {
  private:
    int m_X, m_Y;
    mutable int var;
  public:
    int GetX() const {
      std::cout << "const getx" << std::endl;
      var = 2;
      return m_X;
    }

    int GetX() {
      std::cout << "not const getx" << std::endl;
      return m_X;
    }

    void SetX(int x) {
      m_X = x;
    }
};

void PrintEntity(const Entity& e) {
  std::cout << e.GetX() << std::endl;
}

void PrintEntity2(Entity& e) {
  std::cout << e.GetX() << std::endl;
}

int main() {
  const int MAX_AGE = 83;
  
  const int* const a = new int;
//  *a = 2;
//
//  a = (int*)&MAX_AGE;
  std::cout << *a << std::endl;
  
  Entity e;
  PrintEntity(e);
  PrintEntity2(e);
  std::cin.get();
}