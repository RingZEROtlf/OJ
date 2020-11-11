#include <stdio.h>

int n, a[1000];

int gcd(int x, int y)
{
  return y == 0 ? x : gcd(y, x % y);
}

int main()
{
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        sum += gcd(a[i], a[j]);
      }
    }
    printf("%d\n", sum);
  }
}