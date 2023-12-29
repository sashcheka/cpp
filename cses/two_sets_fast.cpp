#include <iostream>

using namespace std;

inline char* w(int n, char *p) {
  char *s = p;
  do
    *p++ = n % 10 + '0';
  while (n /= 10);

  char *end = p;
  while (--p > s) {
    char temp = *p;
    *p = *s;
    *s++ = temp;
  }

  return end;
}

int main() {

  int n;
  cin >> n;

  if (n%4 == 1 || n%4 == 2) {
    cout << "NO" << endl;
    return 0;
  }

  char *buf = new char[n * 8], *p = buf;
  p += sprintf(p, "YES\n%d\n", n/2);

  for (int i = n; i > 0; i -= 4) {
    p = w(i, p); *p++ = ' ';
    p = w(i - 3, p); *p++ = ' ';
  }
  p -= n & 1; *(p - 1) = '\n';
  
  p = w(n / 2 + (n & 1), p); *p++ = '\n';
  for (int i = n; i > 0; i -= 4) {
    p = w(i - 1, p); *p++ = ' ';
    p = w(i - 2, p); *p++ = ' ';
  }
  *(p - 1) = '\n';

  cout.write(buf, p - buf);

  return 0;
}