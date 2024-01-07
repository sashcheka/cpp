#include <iostream>
#include <vector>

using namespace std;

int main() {
  long n;
  cin >> n;
  
  long num;
  long sum = n * (n + 1) / 2;
    
  while (cin >> num) {
    sum -= num;
  }
  
  cout << sum;

  return 0;
}