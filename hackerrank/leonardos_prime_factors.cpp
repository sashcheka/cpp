#include <iostream>
#include <cmath>
#include <type_traits>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int primeCount(long n) {
  vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
  unsigned long long p = 1;
  int i = 0;

  while(1) {
    p *= primes[i];
    if (p > n)
      return i;
    i++;
  }
  return 0;
}

int main() {
  long n;
  cin >> n;
  
  int m = primeCount(n);
  cout << m;
}
