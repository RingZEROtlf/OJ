#include <stdio.h>

int main()
{
  int x;
  while (scanf("%d", &x) == 1) {
    if (x % 2 == 1) {
      printf("ODD\n");
    } else {
      printf("EVEN\n");
    }
  }
}