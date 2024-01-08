#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  
  string p = s;
  reverse(p.begin(), p.end());
  s += p;
  
  cout << s;
}