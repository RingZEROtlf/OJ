#include <iostream>
#include <algorithm>

int main()
{
  int K, r, x = 0;
  std::cin >> K;
  while (K--) {
    std::cin >> r;
    x = std::max(x, r);
  }
  if (x <= 25) {
    std::cout << "0\n";
  } else {
    std::cout << x - 25 << '\n';
  }
}