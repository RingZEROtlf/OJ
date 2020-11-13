#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
  int n;
  std::vector<std::string> maganets;
  std::string s;
  std::cin >> n;
  while (n--) {
    std::cin >> s;
    maganets.push_back(s);
  }
  maganets.erase(std::unique(maganets.begin(), maganets.end()), maganets.end());
  std::cout << maganets.size() << '\n';
}