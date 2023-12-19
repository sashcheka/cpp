#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  vector<string> answers;
  
  for (int i = 0; i < t; i++) {
    int sum = 0;
    int n;
    cin >> n;
    
    vector<int> employees;
    for (int j = 0; j < n; j++) {
      int empl;
      cin >> empl;
      employees.push_back(empl);      
    }
    
    for (int& empl : employees) {
      sum += empl;
    }
    
    if (n <= 1) {
      answers.push_back("Yes");
      continue;
    }
    
    if (sum % 2 == 0) answers.push_back("Yes");
    else answers.push_back("No");
  }
  
  for (string& ans : answers) {
    cout << ans << endl;
  }
  
  return EXIT_SUCCESS;
}