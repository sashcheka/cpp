#include <iostream>
#include <bitset>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  for (int i = 0; i < 1 << n; i++) {
    bitset<16> binary(i);
    bitset<16> gray = binary ^ (binary >> 1);
    
    for (int j = n - 1; j >= 0; j--) {
      cout << gray[j];
    }
    cout << endl;
  }
}