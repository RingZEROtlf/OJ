#include <iostream>

int main()
{
  int n, h[100], a[100];
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> h[i] >> a[i];
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (h[i] == a[j]) ++count;
      if (a[i] == h[j]) ++count;
    }
  }
  std::cout << count << '\n';
}