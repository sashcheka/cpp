#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < sizeof(arr); i+=4) {
      std::cout << *((int*)((char*)&arr + i)) << " ";
    }
    
}
