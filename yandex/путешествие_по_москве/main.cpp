#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

#define PI 3.141592653589793

int main() {
  std::cout.precision(15);
  std::cout << std::fixed;
  long double x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;

  long double r1 = hypot(x1, y1);
  long double r2 = hypot(x2, y2);

  long double angle1 = atan2(y1, x1);
  long double angle2 = atan2(y2, x2);

  long double angleDiff = angle2 - angle1;

  if (angleDiff < 0) {
    angleDiff += 2 * PI;
  }
  if (angleDiff > PI) {
    angleDiff = 2 * PI - angleDiff;
  }
  
  long double arcL;
  if (r2 >= r1) 
    arcL = angleDiff * r1;
  else
    arcL = angleDiff * r2;

  long double rDiff = abs(r2 - r1);
  long double shortestPath;

  if (r1 + r2 <= arcL + rDiff) {
    shortestPath = r1 + r2;
  } else {
    shortestPath = arcL + rDiff;
  }
  
  std::cout << shortestPath;
}