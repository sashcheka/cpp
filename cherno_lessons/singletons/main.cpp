#include <iostream>

class Random {
public:
  Random(const Random&) = delete;
  Random& operator=(const Random&) = delete;
  
  static Random& Get() {
    static Random instance;
    return instance;
  }
  
  static float Float() { return Get().IFloat(); }
  
private:
  float IFloat() { return m_RandomGenerator; }
  
  Random() {}
  
  float m_RandomGenerator = 0.5f;
  
};

int main() {
  float number = Random::Float();
  Random& notassign = Random::Get();
  Random notcopy = Random::Get();
  
  notassign = notcopy;
  
  std::cout << number << std::endl;
  std::cin.get();
}