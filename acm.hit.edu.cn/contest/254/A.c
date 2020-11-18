#include <stdio.h>

int T, n, m, x[100001];

int min(int a, int b)
{
  return a < b ? a : b;
}

int check(int D)
{
  int jump = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j <= n && x[j] - x[i] <= D) ++j;
    if (j != n + 1 && i + 1 == j) return 0;
    i = j - 1;
    ++jump;
  }
  return jump <= m;
}

int main()
{
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
    }
    int L = 1, R = 1e8 + 1, t = 1e8 + 1;
    while (L + 1 < R) {
      int D = (L + R) / 2;
      if (check(D)) {
        t = min(t, D);
        R = D;
      } else {
        L = D + 1;
      }
    }
    printf("Case #%d: %d\n", cas, check(L) ? L : t);
  }
}