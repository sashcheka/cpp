#include <iostream>
#include <string>

class Entity {
  protected:
    int X, Y;
  private:
    void Print();
  public:
    Entity() {
      X = 0;
    }
    
};

class Player : public Entity {
  public:
    Player() {
      X = 2;
      Print();
    }
};

int main() {
  Entity e;
  e.X = 2;
  e.Print();
  std::cin.get();
}