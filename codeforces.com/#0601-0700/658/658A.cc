#include <iostream>
#include <algorithm>

int main()
{
  int n, c, p[50], t[50];
  std::cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i];
  }
  int L = 0, R = 0;
  for (int i = 0, x = 0; i < n; ++i) {
    x += t[i];
    L += std::max(0, p[i] - c * x);
  }
  for (int i = n - 1, x = 0; i >= 0; --i) {
    x += t[i];
    R += std::max(0, p[i] - c * x);
  }
  if (L < R) {
    std::cout << "Radewoosh\n";
  } else if (L > R) {
    std::cout << "Limak\n";
  } else {
    std::cout << "Tie\n";
  }
}