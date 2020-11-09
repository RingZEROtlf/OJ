#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
  std::string s;
  std::cin >> s;
  std::vector<int> vec;
  for (int i = 0; i < s.length(); i += 2) {
    vec.push_back(s[i] - '0');
  }
  std::sort(vec.begin(), vec.end());
  std::cout << vec[0];
  for (int i = 1; i < vec.size(); ++i) {
    std::cout << '+' << vec[i];
  }
  std::cout << '\n';
}