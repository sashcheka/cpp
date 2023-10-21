#include <iostream>
using namespace std;

class Funij
{
public:
  unsigned long long sumin(unsigned long long n)
{
    return static_cast<unsigned long long>(n * (n + 1) * (2 * n + 1) / 6);
  }

  unsigned long long sumax(unsigned long long n)
{
    return static_cast<unsigned long long>(n * (n + 1) * (4 * n - 1) / 6);
  }

  unsigned long long sumsum(unsigned long long n)
{
    return static_cast<unsigned long long>(n * n * (n + 1));
  }
};

int main() {
  Funij funij;
  int num;
  cin >> num;
  unsigned long long sum = funij.sumax(num);
  cout << sum;
}
