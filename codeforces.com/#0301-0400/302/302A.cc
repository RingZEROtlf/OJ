#include <iostream>
#include <algorithm>

int main()
{
  std::ios::sync_with_stdio(false);
  int n, m, a, x = 0;
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    if (a == -1) ++x;
  }
  x = std::min(x, n - x);
  int l, r;
  while (m--) {
    std::cin >> l >> r;
    int xx = r - l + 1;
    if (xx % 2 == 1) {
      std::cout << "0\n";
    } else if (xx / 2 > x) {
      std::cout << "0\n";
    } else {
      std::cout << "1\n";
    }
  }
}