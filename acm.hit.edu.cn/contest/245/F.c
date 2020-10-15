#include <stdio.h>

int main()
{
  int N, primes[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
  while (scanf("%d", &N) == 1) {
    printf("%d=", N);
    int first = 1;
    for (int i = 0; i < 25 && N > 1; ++i) {
      while (N % primes[i] == 0) {
        if (first) {
          printf("%d", primes[i]);
          first = 0;
        } else {
          printf("*%d", primes[i]);
        }
        N /= primes[i];
      }
    }
    printf("\n");
  }
}