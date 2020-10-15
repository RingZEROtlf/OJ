#include <stdio.h>

int main()
{
  int N;
  while (scanf("%d", &N) == 1) {
    int is_prime = 1;
    for (int i = 2; i * i <= N; ++i) {
      if (N % i == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}