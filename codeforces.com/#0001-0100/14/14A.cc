#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

int main()
{
  int n, m;
  std::string graph[50];
  std::cin >> n >> m;
  int x0, y0, x1, y1;
  x0 = y0 = std::numeric_limits<int>::max();
  x1 = y1 = std::numeric_limits<int>::min();
  for (int i = 0; i < n; ++i) {
    std::cin >> graph[i];
    for (int j = 0; j < m; ++j) {
      if (graph[i][j] == '*') {
        x0 = std::min(x0, i);
        y0 = std::min(y0, j);
        x1 = std::max(x1, i);
        y1 = std::max(y1, j);
      }
    }
  }
  for (int i = x0; i <= x1; ++i) {
    for (int j = y0; j <= y1; ++j) {
      std::cout << graph[i][j];
    }
    std::cout << '\n';
  }
}