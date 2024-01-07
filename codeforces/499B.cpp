#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  unordered_map<string, string> umap;
  string s1, s2, p;
  
  while(m--) {
    cin >> s1 >> s2;
    umap[s1] = s2;
  }
  
  while(n--) {
    cin >> p;
    if (p.size() <= umap[p].size())
      cout << p << ' ';
    else
      cout << umap[p] << ' ';
  }
}