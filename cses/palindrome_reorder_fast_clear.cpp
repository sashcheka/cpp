#include <iostream>

using namespace std;

char s[1000001];
int cnt[26] = {0};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> s;
  
  int n = 0;
  for (; s[n] != '\0'; n++)
    cnt[s[n] - 'A']++;
  
  int odd = (n & 1) ? -1 : 0;
  int j = 0;
  
  for (int i = 0; i < 26; i++) {
    
    if (cnt[i] & 1) {
      odd++;
      if (odd) break;
      s[n / 2] = i + 'A';
    }
    
    for (int k = cnt[i] / 2; k > 0; k--, j++)
      s[j] = i + 'A', s[n - j - 1] = i + 'A';
  }
  
  if (odd)
    cout << "NO SOLUTION";
  else
    cout << s;
}