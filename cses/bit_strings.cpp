#include <iostream>

using namespace std;

#define m 1000000007

int main() {
  int n, r, b;
  cin >> n;
  
  r = 1;
  b = 2;
  
  while(n > 0) {
    if (n & 1)
      r = (long long)r * b % m;
    b = (long long)b * b % m;
    n >>= 1;
  }
  
  cout << r;

  return 0;
}