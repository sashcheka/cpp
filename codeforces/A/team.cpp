#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int c = 0;
  
  for (int i = 0; i < n; i++){
    bool p, v, t;
    cin >> p >> v >> t;
    if (p + v + t > 1)
      c++;
  }
  
  cout << c;
}