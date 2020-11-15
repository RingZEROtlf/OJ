#include <iostream>
#include <unordered_set>

int main()
{
  int s;
  std::unordered_set<int> set;
  for (int i = 0; i < 4; ++i) {
    std::cin >> s;
    set.insert(s);
  }
  std::cout << 4 - set.size() << '\n';
}