#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> f(m);
  for (int i = 0; i < m; i++) 
    cin >> f[i];
  
  sort(f.begin(), f.end());
  
  int curr_diff, min_diff = 997;
  
  for (int i = n - 1; i < m; i++) {
    curr_diff = f[i] - f[i - (n - 1)];
    min_diff = min(min_diff, curr_diff);
  }
  
  cout << min_diff;
}