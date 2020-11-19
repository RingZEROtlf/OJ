#include <iostream>
#include <algorithm>

int main()
{
  int n, k, x, a[100];
  std::cin >> n >> k >> x;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int result = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (x < a[i] && k > 0) {
      result += x;
      --k;
    } else {
      result += a[i];
    }
  }
  std::cout << result << '\n';
}