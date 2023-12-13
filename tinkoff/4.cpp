#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool Comparator(int a, int b) {
  std::string aStr = std::to_string(a);
  std::string bStr = std::to_string(b);

  if (aStr.length() != bStr.length()) {
    return aStr.length() > bStr.length();
  }

  return a < b;
}

int main() {
//  int n, k;
//  std::cin >> n >> k;
//  
//  std::vector<int> nums(n);
//  int start_sum = 0;
//  int end_sum = 0;
//  
//  for (int i = 0; i < n; i++) {
//    std::cin >> nums[i];
//    start_sum += nums[i];
//  }

  std::vector<int> nums = { 5, 32, 120, 530, 840, 69, 1 };
  
  std::sort(nums.begin(), nums.end(), Comparator);
  for (int num : nums) {
    std::cout << num << " ";
  }
  
//  std::cout << start_sum;
  
  return EXIT_SUCCESS;
}