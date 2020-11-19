#include <iostream>
#include <unordered_map>

int main()
{
  int a, b, c, n, x;
  std::cin >> a >> b >> c;
  std::cin >> n;
  std::unordered_map<int, int> safe_map;
  while (n--) {
    std::cin >> x;
    ++safe_map[x];
  }
  int result = 0;
  for (auto &[pos, count]: safe_map) {
    if (b < pos && pos < c) {
      result += count;
    }
  }
  std::cout << result << '\n';
}