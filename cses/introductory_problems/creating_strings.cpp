#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> v;
  
  sort(s.begin(), s.end());
  do {
    v.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
  
  cout << v.size() << endl;
  for (string& str : v)
    cout << str << endl;
}