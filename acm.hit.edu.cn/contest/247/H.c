#include <stdio.h>

int main()
{
  int T, G, L;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &G, &L);
    if (L % G == 0) {
      printf("%d %d\n", G, L);
    } else {
      printf("-1\n");
    }
  }
}