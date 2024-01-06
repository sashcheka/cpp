#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  
  int t, n, inf = 200001;
  int a[200001];
  cin >> t;

  while(t--){
    cin >> n;

    for (int i = 0; i < n; i++)
      cin >> a[i];

    int b = inf, c = inf;
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (b > c)
        swap(b, c);

      if (a[i] <= b) 
        b = a[i];
      else if (a[i] <= c) 
        c = a[i];
      else 
        b = a[i], ans++;

    }
    cout << ans << '\n';
  }
}