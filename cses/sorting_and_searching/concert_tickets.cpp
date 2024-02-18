#include <iostream>
#include <set>
#include <array>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  set<array<int, 2>> s;

  int h, t;
  for (int i = 0; i < n; i++) {
    cin >> h;
    s.insert({h, i});
  }

  for (int i = 0; i < m; i++) {
    cin >> t;
    
    auto it = s.lower_bound({t + 1, 0});
    
    if (it == s.begin())
      cout << -1 << '\n';
    else {
      --it;
      cout << (*it)[0] << '\n';
      s.erase(it);
    }
  }
}