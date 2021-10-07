#include <iostream>

class multiples_of_3_or_5 {
 public:
  uint64_t operator()(uint64_t n) const {
    uint64_t _3 = (n - 1) / 3, _5 = (n - 1) / 5, _15 = (n - 1) / 15;
    return (_3 * (_3 + 1) * 3 + _5 * (_5 + 1) * 5 - _15 * (_15 + 1) * 15) / 2;
  }
};

int main() {
  multiples_of_3_or_5 f;
  std::cout << f(1000) << std::endl;
}
