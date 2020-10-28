#include <stdio.h>
#include <stdint.h>

int T, N, M;
int64_t A[100000];

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &M);
    int L = 1, R = 1;
    int64_t sum = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
      R = max(A[i] + 1, R);
      sum += A[i];
    }
    if (sum < M) {
      printf("0\n");
      continue;
    }
    
    while (L + 1 < R) {
      int x = (L + R) / 2;
      int64_t total = 0;
      for (int i = 0; i < N; ++i) {
        total += A[i] / x;
      }
      if (total >= M) {
        L = x;
      } else {
        R = x;
      }
    }
    printf("%d\n", L);
  }
}