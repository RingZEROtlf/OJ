#include <iostream>

int main()
{
  long long n;
  std::cin >> n;
  if (n % 2 == 1) {
    std::cout << '-';
  }
  std::cout << (n + 1) / 2 << '\n';
}