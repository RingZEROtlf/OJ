#include <stdio.h>

int main()
{
  int X, Y, Z;
  while (scanf("%d %d %d", &X, &Y, &Z) == 3) {
    printf("%d\n", X + Y - Z);
  }
}