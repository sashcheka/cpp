#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int restaurant(int l, int b) {
  int side = gcd(l, b);

  int n = (l/side) * (b/side);

  return n;
}

int main() {
  int l ,b;
  cin >> l >> b;
  
  int n = restaurant(l ,b);
  
  cout << n;
}