#include <stdio.h>

int N, A[1000];

int main()
{
  while (scanf("%d", &N) == 1) {
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    int pass = 0;
    while (1) {
      int swapped = 0;
      for (int i = 1; i < N; ++i) {
        if (A[i - 1] > A[i]) {
          int tmp = A[i - 1];
          A[i - 1] = A[i];
          A[i] = tmp;
          swapped = 1;
        }
      }
      if (swapped) {
        ++pass;
      } else {
        break;
      }
    }
    printf("%d\n", pass);
  }
}