#include <iostream>
#include <string>

int main()
{
  std::string s1, s2;
  std::cin >> s1 >> s2;
  for (auto &c: s1) {
    c = tolower(c);
  }
  for (auto &c: s2) {
    c = tolower(c);
  }
  if (s1 < s2) {
    std::cout << "-1\n";
  } else if (s1 == s2) {
    std::cout << "0\n";
  } else {
    std::cout << "1\n";
  }
}