#include <stdio.h>
#include <string.h>

char x[200005];

int main()
{
  while (scanf("%s", x) == 1) {
    int xx = x[strlen(x) - 1] - '0';
    if (xx % 2 == 0) {
      printf("EVEN\n");
    } else {
      printf("ODD\n");
    }
  }
}