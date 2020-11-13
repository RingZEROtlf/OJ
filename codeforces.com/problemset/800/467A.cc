#include <iostream>

int main()
{
  int n, p, q, result = 0;
  std::cin >> n;
  while (n--) {
    std::cin >> p >> q;
    if (p + 2 <= q) {
      ++result;
    }
  }
  std::cout << result << '\n';
}