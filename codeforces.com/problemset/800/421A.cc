#include <iostream>

int main()
{
  int n, a, b, v;
  bool arth[100] = { false }, alex[100] = { false };
  std::cin >> n >> a >> b;
  for (int i = 0; i < a; ++i) {
    std::cin >> v;
    arth[v - 1] = true;
  }
  for (int i = 0; i < b; ++i) {
    std::cin >> v;
    alex[v - 1] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) std::cout << ' ';
    if (arth[i]) {
      std::cout << 1;
    } else {
      std::cout << 2;
    }
  }
  std::cout << '\n';
}