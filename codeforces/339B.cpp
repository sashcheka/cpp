#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  int n, m, a;
  cin >> n >> m;
  
  int c = 1;
  ll t = 0;
  for (int i = 0; i < m; i++) {
    cin >> a;
    if (a > c)
      t += a - c;
    
    if (a < c)
      t += n - (c - a);
    
    c = a;
  }
  
  cout << t;

}