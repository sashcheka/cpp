#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  if (s.length() < 5) {
    cout << "NO";
    return 0;
  }
  
  string h = "hello";
  int j = 0;
  
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == h[j])
      j++;
    
    if (j == 5) {
      cout << "YES";
      return 0;
    }
  }
  
  cout << "NO";
  
}