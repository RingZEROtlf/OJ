#include <stdio.h>
#include <string.h>

int data[362880], head = 0, tail = 0;

int empty()
{
  return head == tail;
}

void push(int x)
{
  data[tail++] = x;
}

int pop()
{
  return data[head++];
}

int moves[362880];
int x = 8, a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
int dx[4] = { -3, 3, -1, 1 };

int lowbit(int x)
{
  return x & (-x);
}

int cantor_expansion()
{
  int bit[10] = { 0 }, t = 1, ret = 0;
  for (int i = 1; i <= 9; ++i) {
    int x = a[9 - i] + 1, query = 0;
    while (x > 0) {
      query += bit[x];
      x -= lowbit(x);
    }
    ret += query * t;
    x = a[9 - i] + 1;
    while (x < 10) {
      bit[x] += 1;
      x += lowbit(x);
    }
    t *= i;
  }
  return ret;
}

void reverse_cantor_expansion(int X)
{
  int mod = 362880, flag[9] = { 0 };
  for (int i = 9; i > 0; --i) {
    mod /= i;
    int xx = X / mod;
    for (int j = 0, k = 0; j < 9; ++j) {
      if (flag[j] == 0) ++k;
      if (k > xx) {
        flag[j] = 1;
        a[9 - i] = j;
        break;
      }
    }
    if (a[9 - i] == 0) x = 9 - i;
    X %= mod;
  }
}

void bfs()
{
  int X = cantor_expansion();
  moves[X] = 1;
  push(X);
  while (!empty()) {
    int curr = pop();
    reverse_cantor_expansion(curr);
    for (int i = 0; i < 4; ++i) {
      if (x % 3 == 0 && dx[i] == -1) continue;
      if (x % 3 == 2 && dx[i] == 1) continue;
      int xx = x + dx[i];
      if (0 <= xx && xx < 9) {
        a[x] = a[xx];
        a[xx] = 0;
        int next = cantor_expansion();
        if (moves[next] == 0) {
          moves[next] = moves[curr] + 1;
          push(next);
        }
        a[xx] = a[x];
        a[x] = 0;
      }
    }
  }
}

int main()
{
  bfs();
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    for (int i = 0; i < 9; ++i) {
      scanf("%d", &a[i]);
    }
    printf("Case #%d: %d\n", cas, moves[cantor_expansion()] - 1);
  }
}