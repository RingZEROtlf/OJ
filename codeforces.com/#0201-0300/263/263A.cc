#include <iostream>
#include <cmath>

int main()
{
  int v, x, y;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      std::cin >> v;
      if (v == 1) {
        x = i, y = j;
      }
    }
  }
  std::cout << std::abs(x - 2) + std::abs(y - 2) << '\n';
}