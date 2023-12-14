#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;
  int temp;
  std::priority_queue<int> max_queue;

  for (int i = 0; i < n; i++) {
    std::cin >> temp;
    int weight = 1;
    while (temp > 0) {
      int digit = temp % 10;
      int gain = (9 - digit) * weight;
      max_queue.push(gain);
      weight *= 10;
      temp /= 10;
    }
  }

//  while (!max_queue.empty()) {
//    std::cout << max_queue.top() << std::endl;
//    max_queue.pop();
//  }

  long int ans = 0;
  for (int i = 0; i < k; i++) {
    if (!max_queue.empty()) {
      int top = max_queue.top();
      ans += top;
      max_queue.pop();
    }
  }

  std::cout << ans;
  
  return EXIT_SUCCESS;
}