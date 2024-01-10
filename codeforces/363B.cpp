#include <iostream>

using namespace std;

int main() {
  int n, k, h, sum = 0;
  cin >> n >> k;
  int a[n];
  
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  for (int i = 0; i < k; i++) 
    sum += a[i];
  
  int ans = sum;
  int j = 0;
  
  for (int i = k; i < n; i++) {
    sum += a[i] - a[i - k];
    if (sum < ans) {
      ans = sum;
      j = i - k + 1;
    }
  }
  
  cout << j + 1;
}