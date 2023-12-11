#include <iostream>

int main() {
  int n, t, e;
  std::cin >> n >> t;
  int floors[n];

  for (int i = 0; i < n; i++) {
    std::cin >> floors[i];
  }

  std::cin >> e;

  int cf = floors[e - 1];
  int ff = floors[0];
  int lf = floors[n - 1];
  
  if (e == 1 || e == n || std::min(cf - ff, lf - cf) <= t)
    std::cout << lf - ff;
  else
    std::cout << std::min(cf - ff, lf - cf) + lf - ff;
  
  
  return EXIT_SUCCESS;
}