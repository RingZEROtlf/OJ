#include <iostream>
#include <string>

int main()
{
  std::string s, pattern = "heidi";
  bool f[6] = { true, false };
  std::cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    for (int j = 5; j > 0; --j) {
      f[j] |= f[j - 1] && (s[i] == pattern[j - 1]);
    }
  }
  if (f[5]) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}