#include <iostream>

int main()
{
  int n, m;
  std::cin >> n >> m;
  while (m > 0) {
    std::cout << n / m;
    n -= n / m;
    --m;
    if (m > 0) {
      std::cout << ' ';
    } else {
      std::cout << '\n';
    }
  }
}