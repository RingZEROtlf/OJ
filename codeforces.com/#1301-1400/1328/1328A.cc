#include <iostream>

int main()
{
  int t, a, b;
  std::cin >> t;
  while (t--) {
    std::cin >> a >> b;
    if (a % b == 0) {
      std::cout << "0\n";
    } else {
      std::cout << b - a % b << '\n';
    }
  }
}