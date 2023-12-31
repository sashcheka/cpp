#include <iostream>

using namespace std;

char gray_code[17];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  int lim = 1<<n;
  fill(gray_code, gray_code + n, '0');
  gray_code[n] = '\n';
  
  int curr_num, bit_pos;
  
  for (int i = 1; i <= lim; i++) {
    cout << gray_code;
    curr_num = i;
    bit_pos = n - 1;
    while (!(curr_num&1)) {
      curr_num >>= 1;
      bit_pos--;
    }
    
    gray_code[bit_pos] = 97 - gray_code[bit_pos];
      
  }
}