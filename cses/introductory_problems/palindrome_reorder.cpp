#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  string s;
  int c[26] = {}, c1 = 0;
  cin >> s;
  for (char& ch : s)
    c[ch - 'A']++;
  
  for (int i = 0; i < 26; i++)
      c1 += c[i]&1;

  if (c1>1) {
    cout << "NO SOLUTION";
    return 0;
  }
  
  string t;
  for (int i = 0; i < 26; i++)
    if (c[i]&1^1)
      for (int j = 0; j < c[i] / 2; j++)
        t += (char)(i + 'A');
  cout << t;
  
  for (int i = 0; i < 26; i++)
    if (c[i]&1)
      for (int j = 0; j < c[i]; j++)
        cout << (char)(i + 'A');

  reverse(t.begin(), t.end());
  cout << t;
}