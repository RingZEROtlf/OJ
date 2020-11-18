#include <stdio.h>
#include <string.h>

typedef long long int64_t;

int64_t bit[100001];
int T, N, A[100000];

int lowbit(int x)
{
  return x & (-x);
}

void bit_init()
{
  memset(bit, 0, sizeof(bit));
}

int64_t bit_query(int x)
{
  int64_t ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= lowbit(x);
  }
  return ret;
}

void bit_update(int x, int64_t v)
{
  while (x < 100001) {
    bit[x] += v;
    x += lowbit(x);
  }
}

int main()
{
  scanf("%d", &T);
  for (int K = 1; K <= T; ++K) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    bit_init();
    int64_t pairs = 0;
    for (int i = N - 1; i >= 0; --i) {
      pairs += bit_query(A[i]);
      bit_update(A[i], 1);
    }
    printf("Case #%d: %lld\n", K, pairs);
  }
}