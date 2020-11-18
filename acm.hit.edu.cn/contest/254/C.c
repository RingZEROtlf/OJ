#include <stdio.h>

int N;
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { -1, 1, 0, 0 };
char maze[105][105];
int moves[105][105];

int data[10000], head, tail;

int init()
{
  head = tail = 0;
}

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

int main()
{
  while (scanf("%d", &N) == 1) {
    init();
    for (int i = 0; i < N; ++i) {
      scanf("%s", maze[i]);
      for (int j = 0; j < N; ++j) {
        moves[i][j] = -1;
        if (maze[i][j] == 'S') {
          moves[i][j] = 0;
          push(i * N + j);
        }
      }
    }

    int ans = -1;
    while (!empty()) {
      int front = pop();
      int x = front / N, y = front % N;
      if (maze[x][y] == 'T') {
        ans = moves[x][y];
        break;
      }
      for (int i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (0 <= xx && xx < N && 0 <= yy && yy < N && 
            maze[xx][yy] != '#' && moves[xx][yy] == -1) {
          moves[xx][yy] = moves[x][y] + 1;
          push(xx * N + yy);
        }
      }
    }

    printf("%d\n", ans);
  }
}