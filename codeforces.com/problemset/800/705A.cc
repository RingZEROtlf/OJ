#include <iostream>
#include <string>

int main()
{
  int n;
  std::string feeling = "I hate";
  std::cin >> n;
  for (int i = 2; i <= n; ++i) {
    if (i % 2 == 0) {
      feeling += " that I love";
    } else {
      feeling += " that I hate";
    }
  }
  feeling += " it";
  std::cout << feeling << '\n';
}