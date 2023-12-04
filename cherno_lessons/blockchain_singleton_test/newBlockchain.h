#ifndef NEWBLOCKCHAIN_H
#define NEWBLOCKCHAIN_H

#include <iostream>

class Singleton {
private:
    Singleton() {
      std::cout << "singleton" << std::endl;
    }
public:
   static Singleton& Get();
};

#endif