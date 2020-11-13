#include <iostream>

bool has_distinct_digits(int value)
{
  bool digits[10] = { false };
  while (value > 0) {
    if (digits[value % 10]) {
      return false;
    }
    digits[value % 10] = true;
    value /= 10;
  }
  return true;
}

int main()
{
  int y;
  std::cin >> y;
  while (true) {
    ++y;
    if (has_distinct_digits(y)) {
      break;
    }
  }
  std::cout << y << '\n';
}