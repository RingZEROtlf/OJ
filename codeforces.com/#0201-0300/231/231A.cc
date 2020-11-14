#include <iostream>

int main()
{
  int n, ans = 0;
  std::cin >> n;
  while (n--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b + c >= 2) {
      ++ans;
    }
  }
  std::cout << ans << '\n';
}