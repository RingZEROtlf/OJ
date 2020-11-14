#include <iostream>

int main()
{
  int n, curr = 0;
  std::cin >> n;
  for (int i = 1; i < n; ++i) {
    curr = (curr + i) % n;
    if (i != 1) std::cout << ' ';
    std::cout << curr + 1;
  }
  std::cout << '\n';
}