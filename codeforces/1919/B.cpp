#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
  int t, n;
  string s;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int p = 0;
    cin >> n;
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '+')
        p++;
      else
        p--;
    }
    cout << abs(p) << '\n';
  }
}