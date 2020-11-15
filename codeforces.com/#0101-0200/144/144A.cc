#include <iostream>
#include <algorithm>

int main()
{
  int n, a[100], min_pos = 0, max_pos = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] <= a[min_pos]) min_pos = i;
    if (a[max_pos] < a[i]) max_pos = i;
  }
  std::cout << max_pos + n - 1 - min_pos + (min_pos < max_pos ? -1 : 0) << '\n';
}