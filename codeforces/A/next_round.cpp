#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int a, b;
  
  for (int i = 0; i < n; i++)  {
    cin >> a;
    if (a == 0) {
      cout << i;
      return 0;
    }
  }
  
  for (int i = k; i < n; i++) {
    cin >> b;
    if (b != a) {
      cout << i;
      return 0;
    }
  }
  
//  for (int i = 0; i < n; i++)  {
//    if (i < k) {
//      cin >> a;
//      if (a == 0) {
//        cout << i;
//        return 0;
//      }
//    }
//    else {
//      cin >> b;
//      if (b != a) {
//        cout << i;
//        return 0;
//      }
//    }
//  }
  
  cout << n;
}