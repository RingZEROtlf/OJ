#include <iostream>
#include <algorithm>

int n, p[1000];

int main()
{
  std::cin >> n;
  int index = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
    if (p[i] > p[index]) {
      index = i;
    }
  }
  std::sort(p, p + n);
  std::cout << index + 1 << ' ' << p[n - 2] << '\n';
}