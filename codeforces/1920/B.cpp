#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  int t;
  cin >> t;
  
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;
    
    int a[n];
    
    for (int i = 0; i < n; i++)
      cin >> a[i];
    
    sort(a, a + n, greater<int>());
      
    for (int i = 1; i < n; i++)
      a[i] += a[i - 1];
    
    int ans = -1e9;
    
    for (int i = 0; i < k; i++)
      ans = max(ans, a[n - 1] - 2*a[min(i + x, n - 1)] + a[i]);
    
    cout << ans << '\n';
  }
}