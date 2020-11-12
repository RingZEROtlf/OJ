#include <iostream>
#include <string>
#include <cctype>

int main()
{
  std::string s;
  std::cin >> s;
  int lower = 0, upper = 0;
  for (auto &c: s) {
    if (islower(c)) {
      ++lower;
    } else {
      ++upper;
    }
  }
  for (auto &c: s) {
    if (upper > lower) {
      c = toupper(c);
    } else {
      c = tolower(c);
    }
  }
  std::cout << s << '\n';
}