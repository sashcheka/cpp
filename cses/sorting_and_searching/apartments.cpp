#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);

  int n, m, k, c = 0, index = 0;
  cin >> n >> m >> k;
  
  vector<int> appl(n);
  vector<int> apart(m);
  
  for (int i = 0; i < n; i++)
    cin >> appl[i];
  
  for (int i = 0; i < m; i++)
    cin >> apart[i];
  
  sort(appl.begin(), appl.end());
  sort(apart.begin(), apart.end());
  
  for (int i = 0; i < n; i++) {
    while(index < m) {
      if (appl[i] > apart[index] + k)
        index++;
      else if (appl[i] < apart[index] - k)
        break;
      else {
        c++, index++;
        break;
      }
    }
  }
  
  cout << c;
  
}