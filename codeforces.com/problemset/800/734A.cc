#include <iostream>
#include <string>
#include <algorithm>

int main()
{
  int n;
  std::string s;
  std::cin >> n >> s;
  int anton = std::count(s.begin(), s.end(), 'A'), danik = n - anton;
  if (anton > danik) {
    std::cout << "Anton\n";
  } else if (anton < danik) {
    std::cout << "Danik\n";
  } else {
    std::cout << "Friendship\n";
  }
}