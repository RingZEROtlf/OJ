#include <iostream>
#include <algorithm>

int n, a, b, h[2000];

int main()
{
  std::cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i];
  }
  std::sort(h, h + n);
  std::cout << h[b] - h[b - 1] << '\n';
}