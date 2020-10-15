#include <stdio.h>

int main()
{
  int primes[10000], count = 1;
  primes[0] = 2;
  for (int i = 3; i <= 10000; i += 2) {
    int is_prime = 1;
    for (int j = 0; j < count; ++j) {
      if (i % primes[j] == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      primes[count++] = i;
    }
  }
  printf("%d", primes[0]);
  for (int i = 1; i < count; ++i) {
    printf(" %d", primes[i]);
  }
  printf("\n");
}