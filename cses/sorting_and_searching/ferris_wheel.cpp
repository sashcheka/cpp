#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);

  int n, x, ans = 0;
  cin >> n >> x;
  vector<int> p(n);
  
  for (int i = 0; i < n; i++)
    cin >> p[i];
  
  sort(p.begin(), p.end());
    
  int i = 0;
  int j = n - 1;
  
  while(i < j) {
    if (p[i] + p[j] > x) {
      j--;
    } else {
      ans++;
<<<<<<< HEAD
      p[i] = p[j] = 0;
=======
      p[i] = p[j] = -1;
>>>>>>> 0d209cbf3b433484b8355d4a7ea99eda1a914240
      i++;
      j--;
    }
  }
  
  for (int i = 0 ; i < n; i++)
<<<<<<< HEAD
    if (p[i] != 0)
=======
    if (p[i] != -1)
>>>>>>> 0d209cbf3b433484b8355d4a7ea99eda1a914240
      ans++;
  
  cout << ans;
}