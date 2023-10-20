#include <iostream>
#include <string>

class Example {
  public:
    Example() {
      std::cout << "Created Entity!" << std::endl;
    }
    
    Example(int x) {
      std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};

class Entity {
  private:
    std::string m_Name;
    Example m_Example;
  public:
    Entity()
      : m_Example(3)
    {
      m_Name = "Unknown";
    }
    
    Entity(const std::string& name)
      : m_Name(name)
    {
    }
    
    std::string& ChangeName(std::string& name) {
      name += "22";
      m_Name = name;
      std::cout << m_Name <<std::endl;
      return m_Name;
    }
};

int main() {
  Entity e0;
  std::string test = "Test11";
  e0.ChangeName(test);
  std::cin.get();
}