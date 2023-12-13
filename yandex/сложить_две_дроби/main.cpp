#include <algorithm>
#include <iostream>
#include <fstream>

int iteratingGcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int a, b, c, d, m, n;
  std::cin >> a >> b >> c >> d;
  int num = a * d + c * b;
  int denum = b * d;
  int iter = iteratingGcd(num, denum);
  std::cout << num / iter << " " << denum / iter;
}