#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a + n);

  int start = a[0], end = start, count = 1;

  for (int i = 1; i <= n; ++i) {

    if (i < n && abs(a[i] - end) <= 1) {
      end = a[i];
      count++;
    } else {

      if (count >= 3) {
        cout << start << " ... " << end << " ";
      } else {
        for (int j = i - count; j < i; ++j) 
          cout << a[j] << " ";
      }

      if (i < n) 
        start = end = a[i], count = 1;

    }
  }
}
