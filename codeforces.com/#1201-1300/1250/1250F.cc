#include <iostream>
#include <algorithm>
#include <limits>

int main()
{
  int n, result = std::numeric_limits<int>::max();
  std::cin >> n;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      result = std::min(result, 2 * (i + n / i));
    }
  }
  std::cout << result << '\n';
}