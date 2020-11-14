#include <iostream>
#include <string>

bool is_lucky(int number)
{
  if (number == 0) {
    return false;
  }
  while (number > 0) {
    int t = number % 10;
    if (t != 4 && t != 7) {
      return false;
    }
    number /= 10;
  }
  return true;
}

int main()
{
  std::string n;
  std::cin >> n;
  int count = 0;
  for (auto &c: n) {
    if (c == '4' || c == '7') {
      ++count;
    }
  }
  if (is_lucky(count)) {
    std::cout << "YES\n";
  } else {
    std::cout << "NO\n";
  }
}