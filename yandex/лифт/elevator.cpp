#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, k;
  cin >> k;
  cin >> n;
  vector<int> v(n);
  
  for (int i = 0; i < n; i++)
    cin >> v[i];
  
  ull t = 0;
  ll p = 0;
  
  for (int i = n - 1; i >= 0; i--) {
    if (p >= v[i]) {
      p -= v[i];
      continue;
    } else {
      v[i] -= p;
      p = 0;
    }

    ll r = v[i] / k;
    t += r * (i + 1) * 2;
    v[i] -= r * k;

    if (v[i] > 0) {
      p = k - v[i];
      v[i] = 0;
      t += (i + 1) * 2;
    }
  }
  cout << t;
}
