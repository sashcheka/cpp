#include <iostream> 

using namespace std; 

int main() { 
  int t; 
  long long y, x, result; 

  cin >> t; 

  while (t--) { 
    cin >> y >> x;

    if (y == x) { 
      result = y * (y - 1) + 1; 
    } 
    else if (y > x) {
      if (y % 2)
        result = y * (y - 1) + 1 - (y - x);
      else
        result = y * (y - 1) + 1 + (y - x);
    } 
    else if (y < x) {
      if (x % 2)
        result = x * (x - 1) + 1 + (x - y);
      else
        result = x * (x - 1) + 1 - (x - y);
    }
    
    cout << result << endl; 
  } 

  return 0; 
}