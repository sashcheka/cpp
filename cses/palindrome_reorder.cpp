#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  unordered_map<char, int> map;
  int count = 0;
  int size = s.size();
  
  for (char& ch : s) {
    map[ch]++;
  }
  
  for (auto& p : map) {
    if (p.second % 2)
      count++;
  }
  
  if ((size % 2 == 1 && count != 1) || (size % 2 == 0 && count > 0)) {
    cout << "NO SOLUTION";
    return 0;
  }
  
  string pal(size, ' ');
  int l = 0, r = size - 1;
  
  for (auto& p : map) {
    char ch = p.first;
    int count = p.second;
    
    if (count % 2) {
      pal[size / 2] = ch;
      count--;
    }
    
    for (int i = 0; i < count / 2; i++) {
      pal[l++] = ch;
      pal[r--] = ch;
    }
  }

  cout << pal;

  return 0;
}