#include <cstdlib>
#include <iostream>
#include <string>

using String = std::string;

class Entity {
  private:
    String m_Name;
  public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}
    
    const String& GetName() const { return m_Name; }
};

int main() {
  Entity* e = new Entity();
  delete e;
  std::cin.get();
}