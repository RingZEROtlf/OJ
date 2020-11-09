#include <stdio.h>

int main()
{
  int n, x, y, h;
  while (scanf("%d %d %d", &n, &x, &y) == 3) {
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &h);
      if (h <= x) {
        ++c1;
      } else if (h <= y) {
        ++c2;
      }
    }
    printf("%d %d\n", c1, c2);
  }
}