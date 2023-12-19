#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> prices(n);
  
  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }
  
  int l, r;
  
  for (int i = 0; i < n; i++) {
    
    l = prices[i] - 1;
    r = m - prices[i];
    
    if (m >= prices[i]) {
      m = max(l, r);
    }
    else
      m = l;
    
  }
  
  cout << m;
  
  return EXIT_SUCCESS;
}