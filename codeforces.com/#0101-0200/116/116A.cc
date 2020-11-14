#include <iostream>
#include <algorithm>

int main()
{
  int n, a, b, passengers = 0, capacity = 0;
  std::cin >> n;
  while (n--) {
    std::cin >> a >> b;
    passengers += b - a;
    capacity = std::max(capacity, passengers);
  }
  std::cout << capacity << '\n';
}