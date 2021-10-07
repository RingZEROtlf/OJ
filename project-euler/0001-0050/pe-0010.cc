#include <iostream>
#include <vector>

class summation_of_primes {
 public:
  uint64_t operator()(uint64_t n) const {
    uint64_t sum = 0;
    std::vector<bool> not_prime(n + 1, false);
    for (uint64_t p = 2; p <= n; ++p) {
      if (!not_prime[p]) {
        sum += p;
        for (auto pp = p * p; pp <= n; pp += p) {
          not_prime[pp] = true;
        }
      }
    }
    return sum;
  }
};

int main() {
  summation_of_primes f;
  std::cout << f(2000000) << std::endl;
}
