#include <future>
#include <iostream>
#include <string>
#include <memory>

class Entity {
  public:
    Entity() {
      std::cout << "Created Entity!" << std::endl;
    }
    
    ~Entity() {
      std::cout << "Destroyed Entity!" << std::endl;
    }
    
    void DoSomething() {
      std::cout << "Doing Something!" << std::endl;
    }
};

void CreateObjectDirectly() {
  Entity e;
  e.DoSomething();
}

void CreateObjectWithRawPointer() {
  Entity* e = new Entity();
  e->DoSomething();
  delete e;
}

void CreateObjectWithUniquePointer() {
  std::unique_ptr<Entity> e = std::make_unique<Entity>();
  e->DoSomething();
}

void CreateObjectWithSharedPointer() {
  std::shared_ptr<Entity> e1 = std::make_shared<Entity>();
  {
    std::shared_ptr<Entity> e2 = e1;
    e1->DoSomething();
  }
}

void CreateObjectWithWeakPointer() {
  std::weak_ptr<Entity> weakEntity;
  {
    std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
    weakEntity = sharedEntity;
    
    if(auto tempSharedPtr = weakEntity.lock()) {
      tempSharedPtr->DoSomething();
    }
  }
  
  if(auto tempSharedPtr = weakEntity.lock()) {
    
  } else {
    std::cout << "Entity is destroyed, weak pointer is expired" << std::endl;
  }
}

int main() {
  CreateObjectWithWeakPointer();
  
  std::cin.get();
}