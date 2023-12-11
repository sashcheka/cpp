#include <iostream>

int main() {
  int n, i = 0;
  std::cin >> n;
  
  for (int j = 0; j <= 15; j++) {
    n = j;
    i = 0;
    while (n > 1) {
      n = (n + 1) / 2;
      i++;
    }
    std::cout << "n = " << j << "cuts = " << i << "\n";
  }

  std::cout << i << "\n";

  return EXIT_SUCCESS;
}