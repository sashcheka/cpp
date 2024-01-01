#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll tw = 0;
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tw += a[i];
  }
  
  ll md = tw;
  
  for (int i = 0; i < (1<<n); i++) {
    ll sw = 0;
    for (int j = 0; j < n; j++) 
      if (i>>j&1)
        sw += a[j];
    ll cd = abs(tw - 2 * sw);
    md = min(md, cd);
  }
  
  cout << md;
}