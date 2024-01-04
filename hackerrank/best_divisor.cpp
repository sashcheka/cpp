#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  int best = 0;
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    if (n%i)
      continue;
  
    int temp = i;
    int sum = 0;
    while(temp > 0) {
      sum += temp % 10;
      temp /= 10;
    }
    
    if (sum > best) {
      best = sum;
      ans = i;
    }
  }
  
  cout << ans;

  return 0;
}