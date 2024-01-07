#include <stdio.h>

inline int g() {
  int c, n = 0;
  while(1) {
    c = getchar_unlocked();
    if (c < 48) return n;
    n = n * 10 + c - 48;
  }
  return n;
}

int main() {
  int t = g();

  while(t--) {
    int a = g(), b = g();
    
    puts(((a + b) % 3 || a * 2 < b || a > b * 2) ? "NO" : "YES");
  }
}
