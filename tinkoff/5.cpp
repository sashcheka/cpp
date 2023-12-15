#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  long long int l, r;
  cin >> l >> r;
  int count = 0;

  for (int digit = 1; digit <= 9; digit++) {
    long long int repdigit = digit;

    while (repdigit <= r) {
      if (repdigit >= l) 
        count++;
      repdigit = repdigit * 10 + digit;
    }
  }

  cout << count;
  return EXIT_SUCCESS;
}