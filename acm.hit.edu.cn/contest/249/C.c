#include <stdio.h>
#include <stdint.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  int64_t x, cm[12][12];
  for (int i = 1; i <= 12; ++i) {
    cm[i][i] = i;
    for (int j = i + 1; j <= 12; ++j) {
      cm[i][j] = cm[i][j - 1] * j;
    }
  }
  while (scanf("%d", &x) == 1) {
    int lcm = 1;
    for (int i = 1; i <= 12; ++i) {
      for (int j = i + 1; j <= 12; ++j) {
        if (x % cm[i][j] == 0) {
          lcm = max(lcm, j - i + 1);
        }
      }
    }
    printf("%d\n", lcm);
  }
}