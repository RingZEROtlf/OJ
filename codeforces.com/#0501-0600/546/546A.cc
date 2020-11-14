#include <iostream>
#include <cmath>

int main()
{
  int k, n, w;
  std::cin >> k >> n >> w;
  int tot = w * (w + 1) / 2 * k;
  std::cout << std::max(0, tot - n) << '\n';
}