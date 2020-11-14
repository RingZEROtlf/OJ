#include <iostream>
#include <string>

int main()
{
  std::string number;
  std::cin >> number;
  auto dot_pos = number.find('.');
  auto integer_part = number.substr(0, dot_pos);
  auto fractional_part = number.substr(dot_pos + 1);
  if (integer_part.back() == '9') {
    std::cout << "GOTO Vasilisa.\n";
  } else {
    if (fractional_part[0] >= '5') {
      ++integer_part.back();
    }
    std::cout << integer_part << '\n';
  }
}