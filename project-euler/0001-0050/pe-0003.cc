#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

constexpr uint64_t N = 600851475143;

class largest_prime_factor {
 public:
  explicit largest_prime_factor(uint64_t N) {
    std::vector<bool> not_prime(static_cast<size_t>(sqrt(N)) + 1, false);
    for (uint64_t p = 3; p * p <= N; p += 2) {
      if (!not_prime[p]) {
        primes_.push_back(p);
        for (uint64_t pp = p * p; pp * pp <= N; pp += p) {
          not_prime[pp] = true;
        }
      }
    }
  }

  uint64_t operator()(uint64_t n) const {
    uint64_t ret = 0;
    for (auto p : primes_) {
      while (n % p == 0) {
        n /= p;
        ret = std::max(ret, p);
      }
    }
    return std::max(ret, n);
  }

 private:
  std::vector<uint64_t> primes_{2};
};

int main() {
  largest_prime_factor f{N};
  std::cout << f(N) << std::endl;
}
