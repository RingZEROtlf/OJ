#include <stdio.h>

int primes[4000], prime_count = 0;
int palindrome_primes[6000], count = 0;

void prepare_primes()
{
  primes[prime_count++] = 2;
  for (int value = 3; value * value <= 1e9; value += 2) {
    int is_prime = 1;
    for (int i = 0; i < prime_count && primes[i] * primes[i] <= value; ++i) {
      if (value % primes[i] == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      primes[prime_count++] = value;
    }
  }
}

int is_prime(int value)
{
  for (int i = 0; i < prime_count && primes[i] * primes[i] <= value; ++i) {
    if (value % primes[i] == 0) {
      return 0;
    }
  }
  return 1;
}

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

void prepare_palindrome_primes()
{
  palindrome_primes[count++] = 5;
  palindrome_primes[count++] = 7;
  for (int half = 1; half < 10000; ++half) {
    int remain = half, reverse = 0, base = 1;
    while (remain > 0) {
      reverse = reverse * 10 + (remain % 10);
      remain /= 10;
      base *= 10;
    }
    int even = half * base + reverse;
    if (is_prime(even)) {
      palindrome_primes[count++] = even;
    }
    for (int digit = 0; digit < 10; ++digit) {
      int odd = (half * 10 + digit) * base + reverse;
      if (is_prime(odd)) {
        palindrome_primes[count++] = odd;
      }
    }
  }
}

int main()
{
  prepare_primes();
  prepare_palindrome_primes();
  for (int i = 0; i < count; ++i) {
    for (int j = i + 1; j < count; ++j) {
      if (palindrome_primes[i] > palindrome_primes[j]) {
        int temp = palindrome_primes[i];
        palindrome_primes[i] = palindrome_primes[j];
        palindrome_primes[j] = temp;
      }
    }
  }
  int a, b;
  scanf("%d %d", &a, &b);
  for (int i = 0; i < count; ++i) {
    if (a <= palindrome_primes[i] && palindrome_primes[i] <= b) {
      printf("%d\n", palindrome_primes[i]);
    }
  }
}