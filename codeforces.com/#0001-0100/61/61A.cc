#include <iostream>
#include <string>
#include <bitset>

int main()
{
  std::string sa, sb;
  std::cin >> sa >> sb;
  std::bitset<100> a(sa), b(sb);
  std::cout << (a ^ b).to_string().substr(100 - sa.length()) << '\n';
}