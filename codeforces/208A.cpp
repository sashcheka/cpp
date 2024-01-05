#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  bool f = 1;
  for (int i = 0; i < s.size(); i++) {
    if(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
      i += 2;
      if (!f)
        cout << ' ';
      f = 1;
    } else {
      f = 0;
      cout << s[i];
    }
  }
}