#include <iostream>

using namespace std;

void move(int n, char l, char r, char m) {
  if (n == 0) 
    return;
  
  move(n - 1, l, m, r);
  cout << l << ' ' << r << endl;
  move(n - 1, m, r, l);
}

int main() {
  int n;
  cin >> n;
  
  cout << (1<<n) - 1 << endl;
  
  move(n, '1', '3', '2');
}