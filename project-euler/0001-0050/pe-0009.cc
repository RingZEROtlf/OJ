#include <iostream>

class pythagorean_triplet {
 public:
  uint64_t operator()(uint64_t n) const {
    for (uint64_t a = 1; a < n; ++a) {
      for (uint64_t b = a + 1; b < n; ++b) {
        uint64_t c = n - a - b;
        if (b < c && a * a + b * b == c * c) {
          return a * b * c;
        }
      }
    }
    return 0;
  }
};

int main() {
  pythagorean_triplet f;
  std::cout << f(1000) << std::endl;
}
