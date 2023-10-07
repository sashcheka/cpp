#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& arr) {
  int n = size(arr);
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

int main() {
  vector<int> arr = {3,2,3,1,1,6,7,9,5,5,9,0,4,11,12,8};
  insertion_sort(arr);
  for (int i = 0; i < size(arr); i++) {
    cout << arr[i] << ' ';
  }
}