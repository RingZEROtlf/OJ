#include <iostream>
#include <cstdint>

int main()
{
  int64_t n, k;
  std::cin >> n >> k;
  int64_t winners = n / 2;
  winners = winners / (k + 1) * (k + 1);
  int64_t diplomas = winners / (k + 1), certificates = winners - diplomas;
  std::cout << diplomas << ' ' << certificates << ' ' << n - winners << '\n';
}