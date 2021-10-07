#include <iostream>
#include <vector>

class prime {
 public:
  prime() = default;

  int64_t operator()(int n) {
    if (n > primes_.size()) {
      for (int64_t p = primes_.back() + 2; primes_.size() < n; p += 2) {
        bool is_prime = true;
        for (auto pp : primes_) {
          if (pp * pp > p) {
            break;
          }
          if (p % pp == 0) {
            is_prime = false;
            break;
          }
        }
        if (is_prime) {
          primes_.push_back(p);
        }
      }
    }
    return primes_[n - 1];
  }

 private:
  std::vector<int64_t> primes_{2, 3, 5, 7, 11, 13, 17, 19, 23};
};

int main() {
  prime f;
  std::cout << f(10001) << std::endl;
}
