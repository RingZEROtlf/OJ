#include <iostream>

int n, v;
bool a[100000];

int main()
{
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> v;
    a[v - 1] = true;
  }
  for (int i = 0; i < n; ++i) {
    if (!a[i]) {
      std::cout << i + 1 << '\n';
      break;
    }
  }
}