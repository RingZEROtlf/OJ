#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

constexpr uint64_t N = 1e13;

class S {
 public:
  explicit S(uint64_t N) {
    uint64_t a = 0, b = 1;
    while (b <= N) {
      fibs_.push_back(a + b);
      a = b;
      b = fibs_.back();
    }
  }

  uint64_t operator()(uint64_t n) {
    std::bitset<64> bits;
    int max_position = 0;
    while (n > 0) {
      auto it = --std::upper_bound(fibs_.begin(), fibs_.end(), n);
      bits.set(std::distance(fibs_.begin(), it));
      n -= *it;
    }
    return dfs(bits, 63);
  }

 private:
  uint64_t dfs(std::bitset<64> bits, int pos) {
    if (pos <= 2) {
      return bits.to_ullong() + 1;
    } else {
      int prefix = bits[pos] * 4 + bits[pos - 1] * 2 + bits[pos - 2];
      if (prefix < 4) {  // 0xx
        return dfs(bits, pos - 1);
      } else if (prefix > 5) {  // 11x
        bits.reset(pos);
        return (1ull << pos) + dfs(bits, pos - 1);
      } else if (prefix == 4) {  // 100
        // 000, 001
        uint64_t result = 1ull << (pos - 1);
        // 010, 011
        bits.reset(pos);
        bits.set(pos - 2);
        result += dfs(bits, pos - 2);
        // 100
        bits.reset(pos - 2);
        return result + dfs(bits, pos - 3);
      } else {  // 101
        // 000, 001, 010
        uint64_t result = 3ull << (pos - 2);
        // 100, 101, 011
        bits.reset(pos);
        result += 2 * dfs(bits, pos - 2);
        bits.reset(pos - 2);
        return result - dfs(bits, pos - 3);
      }
    }
  }

  std::vector<uint64_t> fibs_;
};

int main() {
  S S{N};
  std::cout << S(10000000000000) << std::endl;
}
