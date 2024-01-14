#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> m;
    int l = 0;
    int r = 1e9;
    int not_equal = 0;

    while (n--) {
      int a, x;
      cin >> a >> x;

      if (a == 1)
        l = max(l, x);
      else if (a == 2)
        r = min(r, x);
      else
        m.push_back(x);
    }

    for (int& p : m)
      if (p >= l && p <= r)
        not_equal++;

    cout << max(0, r - l + 1 - not_equal) << '\n';
  }
}