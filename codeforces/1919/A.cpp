#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if ((a + b - 1) % 2)
      cout << "Bob" << '\n';
    else
      cout << "Alice" << '\n';
  }
}