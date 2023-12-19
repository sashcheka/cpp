#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.141592653589793

int main() {
  cout.precision(6);
  cout << fixed;
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  double r1 = hypot(x1, y1);
  double r2 = hypot(x2, y2);
  double a1 = atan2(y1, x1);
  double a2 = atan2(y2, x2);

  double angle = abs(a1 - a2);

  double ans1 = angle * min(r1, r2) + abs(r1 - r2);
  double ans2 = r1 + r2;

  cout << min(ans1, ans2);
}