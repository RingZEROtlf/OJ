#include <iostream>
#include <unordered_map>
#include <set>

int main()
{
  int n, r, a;
  std::cin >> n;
  std::unordered_map<int, int> counts;
  for (int i = 0; i < n; ++i) {
    std::cin >> r;
    while (r--) {
      std::cin >> a;
      ++counts[a];
    }
  }
  std::set<int> possible_stops;
  for (auto &[stop, count]: counts) {
    if (count == n) {
      possible_stops.insert(stop);
    }
  }
  bool first = true;
  for (auto &stop: possible_stops) {
    if (!first) std::cout << ' ';
    std::cout << stop;
    first = false;
  }
  std::cout << '\n';
}