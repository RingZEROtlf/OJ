#include <iostream>
#include <string>
#include <cctype>

int main()
{
  std::string password;
  std::cin >> password;
  bool has_upper = false, has_lower = false, has_digit = false;
  for (auto &c: password) {
    has_upper |= isupper(c);
    has_lower |= islower(c);
    has_digit |= isdigit(c);
  }
  if (password.length() >= 5 && has_upper && has_lower && has_digit) {
    std::cout << "Correct\n";
  } else {
    std::cout << "Too weak\n";
  }
}