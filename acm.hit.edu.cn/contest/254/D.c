#include <stdio.h>

int cols[15], main_diags[30], second_diags[30];
int count[15];

void dfs(int row, int N)
{
  if (row == N) ++count[N - 1];
  for (int col = 0; col < N; ++col) {
    int main_diag = row + N - 1 - col;
    int second_diag = row + col - 1;
    if (cols[col] || main_diags[main_diag] || second_diags[second_diag]) {
      continue;
    }
    cols[col] = 1;
    main_diags[main_diag] = 1;
    second_diags[second_diag] = 1;
    dfs(row + 1, N);
    cols[col] = 0;
    main_diags[main_diag] = 0;
    second_diags[second_diag] = 0;
  }
}

int main()
{
  for (int N = 1; N <= 15; ++N) {
    dfs(0, N);
  }
  int N;
  while (scanf("%d", &N) == 1) {
    printf("%d\n", count[N - 1]);
  }
}