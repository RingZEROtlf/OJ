#include <iostream>

int main()
{
  int n, v;
  bool is_hard = false;
  std::cin >> n;
  while (n--) {
    std::cin >> v;
    is_hard |= v;
  }
  if (is_hard) {
    std::cout << "HARD\n";
  } else {
    std::cout << "EASY\n";
  }
}