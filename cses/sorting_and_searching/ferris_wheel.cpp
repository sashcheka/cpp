#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);

  int n, x, ans = 0;
  cin >> n >> x;
  vector<int> p(n);
  
  for (int i = 0; i < n; i++)
    cin >> p[i];
  
  sort(p.begin(), p.end());
    
  int l = 0;
  int r = n - 1;
  
  while (l < r && l < n && r >= 0) {
    if (p[l] + p[r] <= x)
      l++, r--;
    else
      r--;
    ans++;
  }
  
  if (l == r)
    ans++;
  
  cout << ans;
}