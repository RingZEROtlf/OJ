#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

void fill(int *a, int N)
{
  a[0] = N / 1000;
  a[1] = N / 100 % 10;
  a[2] = N / 10 % 10;
  a[3] = N % 10;
}

int main()
{
  int T, N;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &N);
    printf("Case #%d:\n", t);
    do {
      int a[4];
      fill(a, N);
      qsort(a, 4, sizeof(a[0]), compare);
      N = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
      int n = a[3] + a[2] * 10 + a[1] * 100 + a[0] * 1000;
      printf("%04d - %04d = %04d\n", N, n, N - n);
      N = N - n;
    } while (N != 6174 && N != 0);
  }
}