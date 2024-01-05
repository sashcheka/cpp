#include <iostream>
#include <string>

using namespace std;

int main() {
  string p;
  cin >> p;
  
  if (p.find('H') != -1 || p.find('Q') != -1 || p.find('9') != -1)
    cout << "YES";
  else
    cout << "NO";
}