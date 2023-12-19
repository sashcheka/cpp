#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ratings(n);
  vector<int> ans(n, 0);
  int preSum = 0;
  int postSum = 0;
    
  for (int i = 0 ; i < n; i++) {
    cin >> ratings[i];
  }
  
  for (int i = 0; i < n; i++) {
    ans[i] += ratings[i] * (i) - preSum;
    preSum += ratings[i];
  }
  
  for (int i = n - 1; i >= 0; i--) {
    ans[i] += postSum - ratings[i] * (n - i - 1);
    postSum += ratings[i];
  }
  
  for (int i = 0 ; i < n; i++) {
    cout << ans[i] << " ";
  }
  
  return 0;
}