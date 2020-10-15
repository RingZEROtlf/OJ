#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[100001];

int main()
{
  scanf("%s", s);
  for (int i = 1, L = strlen(s); i < L; ++i) {
    if (tolower(s[i - 1]) == 'i' && tolower(s[i]) == 'g') {
      s[i - 1] = 'i';
      s[i] = 'G';
    }
  }
  printf("%s", s);
}