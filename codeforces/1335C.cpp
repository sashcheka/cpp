#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  int t;
  cin >> t;
  
  while(t--) {
    int n;
    cin >> n;
    
    unordered_map<int, int> freq;
    int max_freq = 0;
    
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      freq[a]++;
      max_freq = max(max_freq, freq[a]);
    }
    
    int distinct = freq.size();
    
    int ans = min(max_freq, distinct - (distinct == max_freq));
    cout << ans << '\n';
  }
}