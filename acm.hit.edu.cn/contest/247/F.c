#include <stdio.h>
#include <string.h>

int main()
{
  char clear[26] = {
    'b', 'c', 'u', 'e', 'v', 't', 'n', 'm', 'l', 'j',
    'k', 'i', 'd', 'z', 'x', 'w', 'a', 's', 'r', 'o',
    'h', 'g', 'f', 'p', 'q', 'y'
  };

  char *cipher = "hzuqxxlgdrrlrqii";
  for (int i = 0; i < strlen(cipher); ++i) {
    printf("%c", clear[cipher[i] - 'a']);
  }
  printf("\n");
}