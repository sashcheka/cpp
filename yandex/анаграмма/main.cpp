#include <iostream>
#include <map>

using namespace std;

int main() {
  string s, t;
  map<char, int> map;
  
  cin >> s;
  cin >> t;
  
  for (char& ch : s) {
    map[ch]++;
  }
  
  for (char& ch : t) {
    if (map[ch] > 0) map[ch]--;
    else {
      cout << "NO";
      return 0;
    }  
  }
  
  cout << "YES";
  return 0;
}