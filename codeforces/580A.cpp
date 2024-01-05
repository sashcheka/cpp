#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  if (n == 1) {
    cout << 1;
    return 0;
  }
  
  int p, c;
  cin >> p;
  
  int l = 1, m = 1;
  for (int i = 1; i < n; i++) {
    cin >> c;
    if (c >= p) {
      l++;
      m = max(m, l);
    } else {
      l = 1;
    }
    p = c;
  }
  
  cout << m;
}