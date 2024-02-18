#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;
  
  while(t--) {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int di = 0;
    int ans = 0;
    
    di = s.find("**");
    
    if (di != string::npos) 
      n = di;
    
    for (int i = 0; i < n; i++) 
      if (s[i] == '@')
        ans++;
    
    cout << ans << '\n';
  }
}