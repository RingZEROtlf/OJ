#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
  int n, k, a[50];
  std::cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a, a + n, std::greater<int>());
  std::cout << std::count_if(a, a + n, [&](int v) {
    return v > 0 && v >= a[k - 1];
  }) << '\n';
}