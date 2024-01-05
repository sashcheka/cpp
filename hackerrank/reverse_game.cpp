#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t, n, k;
  cin >> t;
  int pos;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    
    cout << min(1 + 2 * k, 2 * (n - 1 - k)) << '\n';
  }
}

// reversed task, when we want to get elem by index

//int main() {
//  int t, n, pos;
//  cin >> t;
//  int elem;
//  for (int i = 0; i < t; i++) {
//    cin >> n >> pos;
//    
//    if (pos%2)
//      elem = (pos - 1) / 2;
//    else
//      elem = n - 1 - pos / 2;
//    
//    cout << elem << '\n';
//  }
//}

//int main() {
//  int t, n, k;
//  cin >> t;
//  for (int i = 0; i < t; i++) {
//    cin >> n >> k;
//    
//    int pos = k; // 2
//    for (int i = 0; i < n; i++)
//      if (i <= pos)
//        pos = i + (n - 1 - pos);
//    
//    cout << pos << endl;
//  }
//}


/*

0 1 2 3 4 5
5 4 3 2 1 0
5 0 1 2 3 4
5 0 4 3 2 1
5 0 4 1 2 3
5 0 4 1 3 2

5 _ 4 _ 3 _
_ 0 _ 1 _ 2

 */
 