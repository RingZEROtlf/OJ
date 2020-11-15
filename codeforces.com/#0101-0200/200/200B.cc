#include <iostream>

int main()
{
  int n, p, sum = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> p;
    sum += p;
  }
  std::cout << 1.0 * sum / n << '\n';
}