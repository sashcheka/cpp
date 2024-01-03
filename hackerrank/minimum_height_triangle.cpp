#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int area;
  int base;
  cin >> area >> base;
  
  int height = ceil(2.0 * area / base);
  cout << height;
}