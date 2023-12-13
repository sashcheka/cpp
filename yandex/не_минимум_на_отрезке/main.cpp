#include <algorithm>
#include <iostream>
#include <fstream>

int main() {
  std::ifstream ifstream("input.txt");
  std::ofstream ofstream("output.txt");
  int n, m;
  ifstream >> n >> m;
  int nums[n];
  std::pair<int, int> pairs[m];
  
  for (int i = 0; i < n; i++) {
    ifstream >> nums[i];
  }
  
  for (int i = 0; i < m; i++) {
    ifstream >> pairs[i].first >> pairs[i].second;
 }
 
 ifstream.close();
 
 for (int i = 0; i < m; i++) {
   
   if (*std::min_element(nums + pairs[i].first, nums + pairs[i].second + 1) == *std::max_element(nums + pairs[i].first, nums + pairs[i].second + 1))
     ofstream << "NOT FOUND";
   else
     ofstream << *std::max_element(nums + pairs[i].first, nums + pairs[i].second + 1);
   
   if (i < m - 1)
     ofstream << "\n";
 }
 
 ofstream.close();
}