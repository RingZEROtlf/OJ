#include <iostream>
#include <unordered_set>

int main()
{
  std::unordered_set<int> levels;
  int n, p, a;
  std::cin >> n;
  std::cin >> p;
  while (p--) {
    std::cin >> a;
    levels.insert(a);
  }
  std::cin >> p;
  while (p--) {
    std::cin >> a;
    levels.insert(a);
  }
  if (levels.size() == n) {
    std::cout << "I become the guy.\n";
  } else {
    std::cout << "Oh, my keyboard!\n";
  }
}