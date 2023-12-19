#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  if (d <= b){
    std::cout << a << "\n";
    return EXIT_SUCCESS;
  }
  
  int result = a + (d - b) * c;
  std::cout << result << "\n";
  
  return EXIT_SUCCESS;
}