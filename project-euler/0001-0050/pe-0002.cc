#include <iostream>
#include <vector>

class sum_of_even_fibonacci_numbers {
 public:
  uint64_t operator()(uint64_t n) const {
    uint64_t sum = 0, a = 0, b = 1;
    while (a + b < n) {
      uint64_t c = a + b;
      if (c % 2 == 0) {
        sum += c;
      }
      a = b;
      b = c;
    }
    return sum;
  }
};

int main() {
  sum_of_even_fibonacci_numbers f;
  std::cout << f(4000000) << std::endl;
}
