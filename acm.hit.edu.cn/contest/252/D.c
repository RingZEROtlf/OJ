#include <stdio.h>
#include <string.h>

int n, m, a[100][100], aa[100][100];
char s[105];

void swap(int *px, int *py)
{
  int t = *px;
  *px = *py;
  *py = t;
}

int A[4] = { 1, 2, 3, 0 }, B[4] = { 3, 0, 1, 2 }, C[4] = { 1, 0, 3, 2 }, D[4] = { 3, 2, 1, 0 };
int d[4][2][2] = {
  { { 0, 1 }, { 1, 0 } },
  { { 1, 0 }, { 0,-1 } },
  { { 0,-1 }, {-1, 0 } },
  { {-1, 0 }, { 0, 1 } }
};

int main()
{
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    scanf("%s", s);
    int p = 0, nn = n, mm = m, is_clockwise = 1;
    for (int i = 0; s[i] != '\0'; ++i) {
      switch (s[i]) {
        case 'A':
          p = A[p];
          swap(&nn, &mm);
          break;
        case 'B':
          p = B[p];
          swap(&nn, &mm);
          break;
        case 'C':
          p = C[p];
          is_clockwise = 1 - is_clockwise;
          break;
        case 'D':
          p = D[p];
          is_clockwise = 1 - is_clockwise;
          break;
      }
    }
    int x, y;
    switch (p) {
      case 0:
        x = 0, y = 0;
        break;
      case 1:
        x = 0, y = mm - 1;
        break;
      case 2:
        x = nn - 1, y = mm - 1;
        break;
      case 3:
        x = nn - 1, y = 0;
        break;
    }
    int xx = x, yy = y;
    int dxx = d[p][is_clockwise][0], dxy = d[p][is_clockwise][1];
    int dyx = d[p][1-is_clockwise][0], dyy = d[p][1-is_clockwise][1];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        aa[x][y] = a[i][j];
        x += dyx, y += dyy;
        if (!(0 <= x && x < nn && 0 <= y && y < mm)) {
          xx += dxx, yy += dxy;
          x = xx, y = yy;
        }
      }
    }
    for (int i = 0; i < nn; ++i) {
      for (int j = 0; j < mm; ++j) {
        if (j > 0) printf(" ");
        printf("%d", aa[i][j]);
      }
      printf("\n");
    }
  }
}