#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long k, n;
  cin >> k;
  cin >> n;
  vector<long long> a(n);
  
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  unsigned long long t = 0;
  
  while (true) {
    long long topFloor = -1;
    for (long long i = n - 1; i >= 0; i--) {
      if (a[i] > 0) {
        topFloor = i;
        break;
      }
    }
    
    if (topFloor == -1) break;
    
    t += (topFloor + 1) * 2;
    
    long long places = k;
    
    for (long long i = topFloor; i >= 0; i--) {
      long long take = min(a[i], places);
      places -= take;
      a[i] -= take;
      if (places == 0) {
        topFloor = i;
        break;
      }
    }
  }
  
  long long places = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (places >= a[i]) {
      places -= a[i];
    } else {
      a[i] -= places;
      places = 0;
      
      long long repeats = a[i] / k;
      t += repeats * (i + 1) * 2;
      a[i] -= repeats * k;
      
      if (a[i] > 0) {
        t += (i + 1) * 2;
        places = k - a[i];
        a[i] = 0;
      }
    }
  }
  
  cout << t;
  return 0;
}

