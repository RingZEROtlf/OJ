#include <stdio.h>

int n, l, a[100000], aa[100000];

void merge_sort(int a[], int L, int R)
{
  if (L + 1 >= R) return;
  int M = (L + R) / 2;
  merge_sort(a, L, M);
  merge_sort(a, M, R);
  int i = L, j = M, ii = L;
  while (i < M && j < R) {
    if (a[i] < a[j]) {
      aa[ii++] = a[i++];
    } else {
      aa[ii++] = a[j++];
    }
  }
  while (i < M) aa[ii++] = a[i++];
  while (j < R) aa[ii++] = a[j++];
  for (int i = L; i < R; ++i) {
    a[i] = aa[i];
  }
}

int main()
{
  while (scanf("%d", &n) == 1) {
    scanf("%d", &l);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n);
    int i = 0, j = n - 1, result = 0;
    while (i <= j) {
      if (a[i] + a[j] > l) {
        --j;
        ++result;
      } else {
        ++i, --j;
        ++result;
      }
    }
    printf("%d\n", result);
  }
}