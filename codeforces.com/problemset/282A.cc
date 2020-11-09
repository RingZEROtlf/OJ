#include <iostream>
#include <string>

int main()
{
  int n, x = 0;
  std::cin >> n;
  while (n--) {
    std::string statement;
    std::cin >> statement;
    if (statement[0] == '+' || statement[2] == '+') {
      ++x;
    } else {
      --x;
    }
  }
  std::cout << x << '\n';
}