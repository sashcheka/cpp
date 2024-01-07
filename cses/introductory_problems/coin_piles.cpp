#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  
  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 3 || a * 2 < b || a > b * 2)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }

  return 0;
}