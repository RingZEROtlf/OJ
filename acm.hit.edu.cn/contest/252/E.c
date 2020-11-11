#include <stdio.h>
#include <stdint.h>

int64_t n, a[100000];

int64_t max(int64_t a, int64_t b)
{
  return a > b ? a : b;
}

int main()
{
  while (scanf("%lld", &n) == 1) {
    int64_t sum = 0, mmax = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &a[i]);
      sum += a[i];
      if (mmax < a[i]) {
        mmax = a[i];
      }
    }
    printf("%lld\n", max(mmax, (sum + n - 2) / (n - 1)));
  }
}