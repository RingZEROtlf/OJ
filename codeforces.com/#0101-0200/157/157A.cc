#include <iostream>

int n, a[30][30], rows[30], cols[30];

int main()
{
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> a[i][j];
      rows[i] += a[i][j];
      cols[j] += a[i][j];
    }
  }
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (cols[j] > rows[i]) {
        ++count;
      }
    }
  }
  std::cout << count << '\n';
}