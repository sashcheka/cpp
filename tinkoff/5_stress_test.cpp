#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int f(long long int l, long long int r) {
  int count = 0;

  for (int digit = 1; digit <= 9; digit++) {
    long long int repdigit = digit;
    while (repdigit <= r && repdigit >= l) {
      count++;
      repdigit = repdigit * 10 + digit;
    }
  }

  return count;
}

int main() {
  long long int i = 1e18;
  cout << i << " | " << f(1, i) << endl;
  
  return EXIT_SUCCESS;
}