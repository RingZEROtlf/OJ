#include <iostream>
#include <string>

int main()
{
  int n, m, x = 0, y = 0;
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::string line;
    std::cin >> line;
    for (int j = 1; j <= m; ++j) {
      if (line[j - 1] == '*') {
        x ^= i;
        y ^= j;
      }
    }
  }
  std::cout << x << ' ' << y << '\n';
}