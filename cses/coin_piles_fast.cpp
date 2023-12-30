#include <stdio.h>

#define j int

inline j g() {
  j c, n = 0;
  while(1) {
    c = getchar_unlocked();
    if (c < 48) return n;
    n = n * 10 + c - 48;
  }
  return n;
}

j main() {
  j t = g();

  while(t--) {
    j a = g(), b = g();
    
    puts(((a + b) % 3 || a * 2 < b || a > b * 2) ? "NO" : "YES");
  }
}
