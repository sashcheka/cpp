#include <iostream>

using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;

  int a[5] = {0};
  while (n--) {
    int s;
    cin >> s;
    a[s]++;
  }

  ans += a[4];

  int min31 = min(a[3], a[1]);
  ans += min31;
  
  a[3] -= min31;
  a[1] -= min31;
  ans += a[3];

  ans += a[2] / 2;
  a[2] %= 2;
  
  if (a[2])
    ans++, a[1] = max(0, a[1] - 2);
 
  ans += (a[1] + 3) / 4;
  
  cout << ans;  
}