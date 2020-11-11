#include <stdio.h>
#include <math.h>

int main()
{
  int n;
  while (scanf("%d", &n) == 1) {
    int L = 0, R = 1e9, ans = 1e9;
    while (L + 1 < R) {
      int x = (L + R) / 2;
      if (x * log10(x) > n - 1) {
        ans = x;
        R = x;
      } else {
        L = x + 1;
      }
    }
    if (L * log10(L) > n - 1) {
      printf("%d\n", L);
    } else {
      printf("%d\n", ans);
    }
  }
}