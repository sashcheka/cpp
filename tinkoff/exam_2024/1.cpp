#include <cmath>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n = 3, ans = 0;
  
  while(n--) {
    double x, y;
    cin >> x >> y;
    
    double res = sqrt(x * x + y * y);
    if (res <= 0.1)
      ans += 3;
    else if (res > 0.1 && res <= 0.8)
      ans += 2;
    else if (res > 0.8 && res <= 1.0)
      ans += 1;
  }
  
  cout << ans;
}