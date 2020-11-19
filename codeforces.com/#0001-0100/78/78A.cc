#include <iostream>
#include <string>

int main()
{
  std::string phrase;
  bool is_haiku = true;
  int syllables[3] = { 5, 7, 5 };
  for (int i = 0; i < 3; ++i) {
    std::getline(std::cin, phrase);
    int vowel = 0;
    for (auto &c: phrase) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        ++vowel;
      }
    }
    if (vowel != syllables[i]) {
      is_haiku = false;
    }
  }
  std::cout << (is_haiku ? "YES\n" : "NO\n");
}