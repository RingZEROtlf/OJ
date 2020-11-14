#include <iostream>
#include <string>

int n;
std::string phone_numbers[30000];

int main()
{
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> phone_numbers[i];
  }
  for (int i = 0; ; ++i) {
    bool flag = true;
    for (int j = 1; j < n; ++j) {
      if (phone_numbers[j][i] != phone_numbers[j - 1][i]) {
        flag = false;
        break;
      }
    }
    if (!flag) {
      std::cout << i << '\n';
      break;
    }
  }
}