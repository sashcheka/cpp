#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
      int n, m;
      cin >> n >> m;
      
      vector<int> v(n);

      int a;
      for (int i = 0; i < n; i++)
        cin >> v[i];
      
      string s;
      cin >> s;

      int l = 0;
      int r = n - 1;
      for (int i = 0; i < n - 1; i++)
        s[i] == 'L' ? l++ : r--;

      assert(l == r);

      vector<int> ans(n);
      ans[n - 1] = v[l] % m;
      
      for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'L')
          ans[i] = (ans[i + 1] * v[--l]) % m;
        else
          ans[i] = (ans[i + 1] * v[++r]) % m;
      }

      assert(l == 0);
      assert(r == n - 1);
      
      for (int& i : ans)
        cout << i << ' ';
      
      cout << '\n';
    }
}
