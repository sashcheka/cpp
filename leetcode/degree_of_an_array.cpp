#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

int findShortestSubArray(vector<int>& nums) {
  unordered_map<int, int> countMap;
  unordered_map<int, pair<int, int>> indexMap;
  int maxFreq = 0, minLen = 50000;
  
  for (int i = 0; i < nums.size(); i++) {
    if (countMap[nums[i]] == 0)
      indexMap[nums[i]].first = i;
    
    countMap[nums[i]]++;
    indexMap[nums[i]].second = i;
    maxFreq = max(maxFreq, countMap[nums[i]]);
  }
  
  for (auto& p : countMap)
    if (p.second == maxFreq)
      minLen = min(minLen, indexMap[p.first].second - indexMap[p.first].first);
  
  return minLen + 1;
}

int main() {
  vector<int> nums = {1,2,2,3,1,4,2};
  
  int f = findShortestSubArray(nums);
  cout << f;
}