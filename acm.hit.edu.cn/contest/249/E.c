#include <stdio.h>
#include <stdbool.h>

#define N 100005

int a[N], b[N], size_2, size_0;

bool check(int x) {
    if (x >= size_2 || size_0 < x) {
        return false;
    }
    int count = 0;
    int first_0_index = 0, second_2_index = x;
    while (count < x) {
        int first_2 = a[count], second_0 = b[size_0 - x + count];
        while (first_0_index < size_0 - x && b[first_0_index] < first_2) {
            ++first_0_index;
        }
        if (first_0_index == size_0 - x) {
            break;
        }
        int first_0 = b[first_0_index];
        while (second_2_index < size_2 && a[second_2_index] < first_0) {
            ++second_2_index;
        }
        if (second_2_index == size_2) {
            break;
        }
        int second_2 = a[second_2_index];
        if (second_2 > second_0) {
            break;
        }
        ++first_0_index, ++second_2_index, ++count;
    }
    return count >= x;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        size_2 = size_0 = 0;
        for (int i = 1; i <= n; i++) {
            int d;
            scanf("%d", &d);
            if (d == 2) {
                a[size_2++] = i;
            } else {
                b[size_0++] = i;
            }
        }
        int l = 0, r = size_2 / 2 + 1;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        printf("%d\n", l - 1);
    }
    return 0;
}