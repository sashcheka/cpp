#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll k, n;
  cin >> k;
  cin >> n;
  vector<ll> v(n);
  
  for (ll i = 0; i < n; i++)
    cin >> v[i];
  
  unsigned long long t = 0;
  ll places = 0;
  
  for (ll i = n - 1; i >= 0; i--) {
    if (places >= v[i]) {
      places -= v[i];
      continue;
    } else {
      v[i] -= places;
      places = 0;
    }
    
    ll ride = v[i] / k;
    t += ride * (i + 1) * 2;
    v[i] -= ride * k;
    
    if (v[i] > 0) {
      t += (i + 1) * 2;
      places = k - v[i];
      v[i] = 0;
    }
  }
  
  cout << t;
}