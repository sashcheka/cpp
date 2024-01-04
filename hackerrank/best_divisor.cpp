#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> nums;
  
  for (int i = 1; i <= n; i++)
    if (n%i == 0)
      nums.push_back(i);

  int max_sum = 0;
  int best_divisor;
  
  for (int num : nums) {
    int temp = num;
    int sum = 0;
    while(num != 0) {
      sum += num % 10;
      num /= 10;
    }
    
    if (sum > max_sum || (sum == max_sum && temp < best_divisor)) {
      best_divisor = temp;
      max_sum = sum;
    }
  }
  
  cout << best_divisor;

  return 0;
}