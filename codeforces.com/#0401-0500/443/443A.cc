#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

int main()
{
  std::string s;
  std::getline(std::cin, s);
  std::unordered_set<char> set;
  for (auto &c: s) {
    if (isalpha(c)) {
      set.insert(c);
    }
  }
  std::cout << set.size() << '\n';
}