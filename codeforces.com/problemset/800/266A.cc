#include <iostream>
#include <string>

int main()
{
  int n, result = 0;
  std::string s;
  std::cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      ++j;
    }
    result += j - i - 1;
    i = j - 1;
  }
  std::cout << result << '\n';
}