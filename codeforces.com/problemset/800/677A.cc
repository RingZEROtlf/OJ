#include <iostream>

int main()
{
  int n, h, a, result = 0;
  std::cin >> n >> h;
  while (n--) {
    std::cin >> a;
    if (a <= h) {
      result += 1;
    } else {
      result += 2;
    }
  }
  std::cout << result << '\n';
}