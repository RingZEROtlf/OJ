#include <stdio.h>

int is_prime(int x)
{
  if (x % 2 == 0) {
    return 0;
  }
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    while (!is_prime(n)) {
      ++n;
    }
    printf("%d\n", n);
  }
}