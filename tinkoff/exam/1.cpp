#include <iostream>
#include <ostream>
#include <vector>
#include <unordered_map>

using namespace std;

string tinkoff = "TINKOFF";  

string f(string& input) {
  unordered_map<char, int> letters;
  
  for (char& c : input) {
    letters[c]++;
  }

  for (char& c : tinkoff) {
    if (letters[c] > 0)
      letters[c]--;
  }

  for (const auto& pair : letters) {
    if (pair.second > 0) {
      return "No";
    }
  }
  
  return "Yes";
}

int main() {
  int n;
  cin >> n;
  string input;
  vector<string> ans;
  
  for (int i = 0; i < n; i++) {
    cin >> input;
    ans.push_back(f(input));
  }
  
  for (string& str : ans) {
    cout << str << endl;
  }
  
  return EXIT_SUCCESS;
}