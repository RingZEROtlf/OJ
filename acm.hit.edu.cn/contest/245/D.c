#include <stdio.h>

int min(int a, int b)
{
  return a < b ? a : b;
}

int main()
{
  int T, N;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 1; i < 2 * N; ++i) {
      for (int j = 1; j < 2 * N; ++j) {
        if (min(i, 2 * N - i) + min(j, 2 * N - j) <= N) {
          printf(".");
        } else {
          printf("*");
        }
      }
      printf("\n");
    }
  }
}