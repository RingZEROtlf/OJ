#include <stdio.h>

int main()
{
  int T, N, t[4] = { 6, 1, 3, 4 };
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    printf("%d\n", (N - 1) / 4 * 6 + t[N % 4]);
  }
}