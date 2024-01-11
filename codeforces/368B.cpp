#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  set<int> s;
  int arr[n], ans[n];
  
  for (int i = n - 1; i >= 0; i--) 
    cin >> arr[i];
  
  for (int i = 0; i < n; i++) {
    s.insert(arr[i]);
    ans[i] = s.size();
  }
  
  int l;
  
  while (m--) {
    cin >> l;
    cout << ans[n - l] << '\n';
  }
    
}