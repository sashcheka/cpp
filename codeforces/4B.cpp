#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
  int d, sum;
  cin >> d >> sum;
  vector<int> ans(d), minT(d), maxT(d);
  
  int totalMin = 0, totalMax = 0;
  
  for (int i = 0; i < d; i++) {
    cin >> minT[i] >> maxT[i];
    totalMin += minT[i];
    totalMax += maxT[i];
    ans[i] += minT[i];
  }
  
  if (sum < totalMin || sum > totalMax) {
    cout << "NO";
    return 0;
  }
  
  int r = sum - totalMin;
  for (int i = 0; i < d && r >= 0; i++) {
    int add = min(r, maxT[i] - minT[i]);
    ans[i] += add;
    r -= add;
  }
  
  cout << "YES" << '\n';
  for (int i = 0; i < d; i++)
    cout << ans[i] << ' ';
  
}