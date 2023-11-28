#include <iostream>
#include <string>

class Entity {
public:
  int x;
public:
  void Print() const { std::cout << "hello" << std::endl; }
};

class ScopetPtr {
private:
  Entity* m_Obj;
  int x;
public:
  ScopetPtr(Entity* entity)
  : m_Obj(entity) {}

  ~ScopetPtr() {
    delete m_Obj;
  }

  Entity* operator->() {
    return m_Obj;
  }

  const Entity* operator->() const {
    return m_Obj;
  }
};

int main() {
  const ScopetPtr entity = new Entity();
  entity->Print();


  Entity e;
  e.x = 1;
  std::cout << e.x << std::endl;

  Entity* ptr = &e;

  ptr->x = 2;

  std::cout << ptr->x << std::endl;

  std::cin.get();
}