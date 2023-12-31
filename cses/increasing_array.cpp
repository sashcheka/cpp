#include <iostream>

using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  ll mx = 0;
  
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    mx = max(x, mx);
    ans += mx - x;
  }
  cout << ans;
}