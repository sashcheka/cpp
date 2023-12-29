#include <iostream>
#include <vector>

using namespace std;

void p(vector<int>& s) {
  cout << s.size() << endl;
  for (int i = s.size() - 1; i >= 0 ; i--) {
    cout << s[i] << " ";
  }
}

int main() {
  int n;
  cin >> n;
  
  if (n % 4 && (n + 1) % 4) {
    cout << "NO";
    return 0;
  }
  
  vector<int> s1, s2;
  int d = n;
  s1.push_back(n);
  
  for (int i = n - 1; i >= 1; i--) {
    if (d >= 0) {
      s2.push_back(i);
      d -= i;
    } else {
      s1.push_back(i);
      d += i;
    }
  }
  
  cout << "YES" << endl;
  p(s1);
  cout << endl;
  p(s2);
  return 0;
}