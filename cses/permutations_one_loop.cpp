#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  if (n == 2 || n == 3) {
    cout << "NO SOLUTION";
    return 0;
  }
  
  for (int i = 1; i <= n; i++) {
    if (i <= n / 2)
      cout << 2 * i << " ";
    else
      cout << 2 * (i - n / 2) - 1 << " ";
  }
  
  return 0;
}