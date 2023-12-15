long double f2(double x1, double y1, double x2, double y2) {
  long double r1 = hypot(x1, y1);
  long double r2 = hypot(x2, y2);
  long double a1 = atan2(y1, x1);
  long double a2 = atan2(y2, x2);
  long double diff = abs(a1 - a2);
  while (diff < 0) diff += 2 * PI;
  while (diff >= 2 * PI) diff -= 2 * PI;
  long double a = min(diff, 2*PI - diff);
  long double ans1 = a * min(r1, r2) + abs(r1 - r2);
  long double ans2 = r1 + r2;
  return min(ans1, ans2);
}