#include <stdio.h>

#define MAX 100000
int T, N, L[MAX], G[MAX];

int main()
{
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &L[i]);
    }
    int front = 1, back = 1;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &G[i]);
      if (L[i] > G[i]) front = 0;
      if (L[N - 1 - i] > G[i]) back = 0;
    }
    if (front && back) {
      printf("both\n");
    } else if (front) {
      printf("front\n");
    } else if (back) {
      printf("back\n");
    } else {
      printf("none\n");
    }
  }
}