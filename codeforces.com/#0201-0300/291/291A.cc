#include <iostream>
#include <unordered_map>

int main()
{
  int n, id;
  std::cin >> n;
  std::unordered_map<int, int> skypes;
  for (int i = 0; i < n; ++i) {
    std::cin >> id;
    if (id == 0) continue;
    ++skypes[id];
  }
  int result = 0;
  for (auto &[id, count]: skypes) {
    if (count > 2) {
      std::cout << "-1\n";
      return 0;
    } else if (count == 2) {
      ++result;
    }
  }
  std::cout << result << '\n';
}