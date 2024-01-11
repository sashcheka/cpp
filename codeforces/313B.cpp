#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m, l, r, ans;
  string s;
  cin >> s;
  cin >> m;
  n = s.length();
  vector<int> p(n, 0);
  
  for (int i = 1; i < n; i++)
    p[i] += p[i - 1] + (s[i] == s[i - 1]);
  
  while (m--) {
    cin >> l >> r;
    ans = p[r - 1] - p[l - 1];
    cout << ans << '\n';
  }
}