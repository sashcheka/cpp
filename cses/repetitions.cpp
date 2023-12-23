#include <iostream>

using namespace std;

int main() {
  string seq;
  
  cin >> seq;
  
  int count = 1;
  int longestRep = 1;
  for (size_t i = 1; i < seq.size(); i++) {
    if (seq[i - 1] == seq[i])
      count++;
    else
      count = 1;
    
    longestRep = max(longestRep, count);
  }
  
  cout << longestRep;
  
  return 0;
}