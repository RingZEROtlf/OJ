#include <iostream>

int main()
{
  int a, b;
  std::cin >> a >> b;
  int i;
  for (i = 0; a <= b; ++i) {
    a *= 3;
    b *= 2;
  }
  std::cout << i << '\n';
}