#include <stdio.h>
#include <string.h>

char expr[1024];

int main()
{
  while (scanf("%s", expr) == 1) {
    long long a = 0, b = 0;
    int passed = 0;
    for (int i = 0; i < strlen(expr); ++i) {
      if (passed) {
        b = b * 10 + expr[i] - '0';
      } else if (expr[i] != '+') {
        a = a * 10 + expr[i] - '0';
      } else {
        passed = 1;
      }
    }
    printf("%lld\n", a + b);
  }
}