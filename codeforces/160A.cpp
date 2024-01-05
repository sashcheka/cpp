#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> coins(n);
  
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    coins[i] = a;
    sum += a;
  }
  
  int c = 0;
  int our_sum = 0;
  sort(coins.rbegin(), coins.rend());
  
  for (int i = 0; i < n; i++) {
      c++;
      our_sum += coins[i];
    if (our_sum > sum / 2) break;
  }
  
  cout << c;
}
