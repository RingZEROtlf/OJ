#include <iostream>
#include <string>

int main()
{
  int n;
  std::cin >> n;
  while (n--) {
    std::string s;
    std::cin >> s;
    if (s.length() > 10) {
      std::cout << s[0] << s.length() - 2 << s.back() << '\n';
    } else {
      std::cout << s << '\n';
    }
  }
}