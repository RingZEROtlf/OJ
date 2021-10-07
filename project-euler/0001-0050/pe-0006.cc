#include <iostream>

class sum_square_difference {
 public:
  int64_t operator()(int64_t n) const {
    int64_t a = n * (n + 1) * (n + 2) / 3;
    int64_t b = n * (n + 1) / 2;
    return b + b * b - a;
  }
};

int main() {
  sum_square_difference f;
  std::cout << f(100) << std::endl;
}
