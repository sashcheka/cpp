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
  int bitmask = 0;

  for (int i = 0; i < (1<<n); i++) {
    ll sw = 0;
    for (int j = 0; j < n; j++) 
      if (i>>j&1)
        sw += a[j];
    ll cd = abs(tw - 2 * sw);
    if (cd < md)
      md = cd, bitmask = i;
    md = min(md, cd);
  }
  
  for (int i = 0; i < n; i++)
    if (bitmask>>i&1)
      cout << a[i] << ' ';
  cout << endl;
  
  for (int i = 0; i < n; i++)
    if (!(bitmask>>i&1))
      cout << a[i] << ' ';
  cout << endl;

  cout << md;
}