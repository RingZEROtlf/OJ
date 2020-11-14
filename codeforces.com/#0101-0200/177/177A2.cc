#include <iostream>

int main()
{
  int n, a, result = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a;
      if (i == j || i + j == n - 1 || i == n / 2 || j == n / 2) {
        result += a;
      }
    }
  }
  std::cout << result << '\n';
}