#include <stdio.h>

const double eps = 1e-6;

int main()
{
  int factors[6] = { 1, -15, 85, -225, 274, -121 };
  double L = 1.5, R = 2.4;
  while (R - L >= eps) {
    double x = (L + R) / 2;
    double f = 0;
    for (int i = 0; i < 6; ++i) {
      f = f * x + factors[i];
    }
    if (f >= 0) {
      L = x;
    } else {
      R = x;
    }
  }
  printf("%.6f\n", R);
}