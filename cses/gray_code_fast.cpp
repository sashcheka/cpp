#include <iostream>

using namespace std;

int main() {
  char binary[17];
  
  int n;
  cin >> n;
  
  int lim = 1<<n;
  fill(binary, binary + n, '0');
  binary[n] = '\n';
  
  int curr_num, bit_pos;
  
  for (int i = 1; i < lim; i++) {
    cout << binary;
    curr_num = i;
    bit_pos = n - 1;
    while (!(curr_num&1)) {
      curr_num = curr_num>>1;
      bit_pos--;
    }
    
    binary[bit_pos] = 1^binary[bit_pos];
      
  }
}