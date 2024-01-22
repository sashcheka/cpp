#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, c = 0, minL = 1000002, maxL = -1;
  string s;
  
  cin >> n;
  cin >> s;
  
  
  for (char& ch : s) {
    if (ch != '#') {
      c++;
    } else {
      minL = min(minL, c);
      maxL = max(maxL, c);
      c = 0;
    }
  }
  
  minL = min(minL, c);
  maxL = max(maxL, c);
  
  cout << minL << ' ' << maxL;
}