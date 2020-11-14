#include <iostream>
#include <string>
#include <unordered_set>

int main()
{
  std::string user_name;
  std::cin >> user_name;
  std::unordered_set<char> set;
  for (auto &c: user_name) {
    set.insert(c);
  }
  if (set.size() % 2 == 0) {
    std::cout << "CHAT WITH HER!\n";
  } else {
    std::cout << "IGNORE HIM!\n";
  }
}