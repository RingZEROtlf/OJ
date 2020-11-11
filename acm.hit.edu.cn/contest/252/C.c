#include <stdio.h>
#include <stdint.h>

int main()
{
  int64_t n;
  while (scanf("%lld", &n) == 1) {
    int64_t x = 0, y, z;
    while ((n - 7 * x) % 4 != 0) {
      ++x;
    }
    y = (n - 7 * x) / 4;
    if (x + y > n) {
      int64_t t = (x + y - n + 2) / 3;
      x += 4 * t;
      y -= 7 * t;
    }
    if (y < 0) {
      printf("0\n");
    } else {
      printf("%lld\n", (y + 6) / 7);
    }
  }
}