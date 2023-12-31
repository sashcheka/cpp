#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 1, c = 0;
  char l = 'A';
  
  for(char& ch : s) {
    if(ch == l) {
      c++;
      ans = max(ans, c);
    } else {
      l = ch;
      c = 1;
    }
  }

  cout << ans;
}