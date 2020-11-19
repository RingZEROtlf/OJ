#include <iostream>
#include <cmath>

int main()
{
  int n, d, h[1000];
  std::cin >> n >> d;
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i];
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (std::abs(h[i] - h[j]) <= d) {
        result += 2;
      }
    }
  }
  std::cout << result << '\n';
}