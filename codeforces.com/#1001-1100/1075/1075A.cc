#include <iostream>
#include <cmath>
#include <cstdint>

int64_t calc(int64_t a, int64_t b, int64_t x, int64_t y)
{
  return std::max(std::abs(a - x), std::abs(b - y));
}

int main()
{
  int64_t n, x, y;
  std::cin >> n >> x >> y;
  int64_t ma = calc(1, 1, x, y), mb = calc(n, n, x, y);
  if (ma <= mb) {
    std::cout << "White\n";
  } else {
    std::cout << "Black\n";
  }
}