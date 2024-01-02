#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

int main() {
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  
  stack<int> st;
  unordered_map<int, int> map;

  for (int i = 0; i < nums2.size(); i++) {
      while (!st.empty() && nums2[i] > st.top()) {
          map[st.top()] = nums2[i];
          st.pop();
      }
      st.push(nums2[i]);
  }

  while(!st.empty()) {
    map[st.top()] = -1;
    st.pop();
  }
  
  for (int i = 0; i < nums1.size(); i++)
    nums1[i] = map[nums1[i]];
    
  for (int n : nums1)
    cout << n << ' ' << endl;
  
  for (auto& p : map)
    cout << p.first << ' ' << p.second << endl;
  
}