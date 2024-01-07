#include <iostream>

using namespace std;

#define t int

char s[1000001];
t cnt[26] = {0};

t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  t n = 0;
  cin >> s;
  
  for (; s[n] != '\0'; n++)
    cnt[s[n] - 'A']++;
  
  t odd = ((n & 1) ? -1 : 0);
  t j = 0;
  
  for (t i = 0; i < 26; i++) {
    
    if (cnt[i] & 1) {
      odd++;
      if (odd) break;
      s[n / 2] = i + 'A';
    }
    
    for (t k = cnt[i] / 2; k > 0; k--, j++)
      s[j] = i + 'A', s[n - j - 1] = i + 'A';

  }
  
  if (odd)
    cout << "NO SOLUTION";
  else
    cout << s;
}