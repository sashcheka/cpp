#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
      ll n, m;
      cin >> n >> m;
      int a[n];
      
      for (int& i : a)
        cin >> i;
      
      string s;
      cin >> s;
      ll l = 0, r = n - 1;
      for (char& ch : s) {
        l += ch == 'L';
        r -= ch == 'R';
      }
      
      ll prod = 1;
      int ans[n];
      for (ll i = n - 1; i >= 0; i--) {
        ll dir = s[i];
        if (dir == 'L') {
          l--;
          prod = (prod * a[l]) % m;
        } else {
          r++;
          prod = (prod * a[r]) % m;
        }
        ans[i] = prod;
      }
      
      for (int& i : ans)
        cout << i << ' ';
      
      cout << '\n';
    }
}
