#include <algorithm>
#include <iostream>
#include <string>

class largest_palindrome_product {
 public:
  uint64_t operator()(uint64_t size) const {
    uint64_t R = 1;
    while (size--) {
      R *= 10;
    }

    uint64_t ret = 0;
    for (uint64_t a = R / 10; a < R; ++a) {
      for (uint64_t b = R / 10; b < R; ++b) {
        if (is_palindrome(a * b)) {
          ret = std::max(ret, a * b);
        }
      }
    }
    return ret;
  }

 private:
  bool is_palindrome(uint64_t a) const {
    auto s = std::to_string(a);
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  largest_palindrome_product f;
  std::cout << f(3) << std::endl;
}
