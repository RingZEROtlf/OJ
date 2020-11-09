#include <stdio.h>
#include <string.h>

#define N 1005

char s[N];

int a[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s), index = -1;
            for (int j = len - 1; j >= 0; j--) {
                if (s[j] == '/') {
                    index = j + 1;
                    break;
                }
            }
            int ans = 0;
            if (index == -1) {
              printf("%d", 1 / 0);
            }
            for (int j = index; j < len; j++) {
                ans *= 10;
                ans += (s[j] - '0');
            }
            a[i] = ans;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            printf("%d%c", a[i], i + 1 == k ? '\n' : ' ');
        }
    }
    return 0;
}