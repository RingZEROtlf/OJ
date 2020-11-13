#include <iostream>

int main()
{
  int n, p, a[100];
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> p;
    a[p - 1] = i;
  }
  std::cout << a[0];
  for (int i = 1; i < n; ++i) {
    std::cout << ' ' << a[i];
  }
  std::cout << '\n';
}