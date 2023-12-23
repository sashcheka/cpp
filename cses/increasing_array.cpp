#include <iostream>
#include <vector>

using namespace std;

int main() {
  unsigned long long n;
  unsigned long long count = 0;
  cin >> n;
  vector<unsigned long long> arr(n);
  
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  for (size_t i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      count += arr[i - 1] - arr[i];
      arr[i] = arr[i - 1];
    }
  }
  
  cout << count;
  
  return 0;
}