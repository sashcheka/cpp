#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cout.precision(4);
  cout << fixed;
  
  int n, g = 100001;
  cin >> n;
  
  vector<int> l(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    l[i] = a;
  }
  
  double ans = l[0];
  for (int i = 1; i < n; i++) {
    ans = (double)(ans + l[i]) / 2;
  }
  
  cout << ans;
}