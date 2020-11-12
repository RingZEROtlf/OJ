#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  int n, t;
  std::string s;
  std::cin >> n >> t >> s;
  while (t--) {
    auto ss = s;
    for (int i = 1; i < s.length(); ++i) {
      if (s[i - 1] == 'B' && s[i] == 'G') {
        std::swap(ss[i - 1], ss[i]);
      }
    }
    s = ss;
  }
  std::cout << s << '\n';
}