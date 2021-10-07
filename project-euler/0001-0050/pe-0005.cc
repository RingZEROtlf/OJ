#include <iostream>

class smallest_multiple {
 public:
  uint64_t operator()(uint64_t n) const {
    uint64_t ret = 1;
    for (uint64_t a = 1; a <= n; ++a) {
      ret = lcm(ret, a);
    }
    return ret;
  }

 private:
  uint64_t lcm(uint64_t a, uint64_t b) const { return a * b / gcd(a, b); }
  uint64_t gcd(uint64_t a, uint64_t b) const {
    return a % b == 0 ? b : gcd(b, a % b);
  }
};

int main() {
  smallest_multiple f;
  std::cout << f(20) << std::endl;
}
