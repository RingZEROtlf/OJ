#include <iostream>

int main()
{
  char matrix[3][5];
  for (int i = 0; i < 3; ++i) {
    std::cin >> matrix[i];
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (matrix[i][j] != matrix[2 - i][2 - j]) {
        std::cout << "NO\n";
        return 0;
      }
    }
  }
  std::cout << "YES\n";
}