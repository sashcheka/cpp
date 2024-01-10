#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n, q, m, ans;
  cin >> n;
  
  int p[n];
  for (int i = 0; i < n; i++)
    cin >> p[i];
  
  sort(p, p + n);
  cin >> q;
  
  while(q--) {
    cin >> m;
    ans = upper_bound(p, p + n, m) - p;
    cout << ans << '\n';
  }
}