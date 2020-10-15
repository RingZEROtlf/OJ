#include <stdio.h>

int N, values[1000];

int get_index(int low, int high)
{
  int pivot = values[low];
  while (low < high) {
    while (low < high && values[high] >= pivot) {
      high--;
    }
    values[low] = values[high];
    while (low < high && values[low] <= pivot) {
      low++;
    }
    values[high] = values[low];
  }
  values[low] = pivot;
  return low;
}

void quick_sort(int low, int high)
{
  if (low < high) {
    int index = get_index(low, high);
    quick_sort(low, index - 1);
    quick_sort(index + 1, high);
  }
}

int main()
{
  while (scanf("%d", &N) == 1) {
    for (int i = 0; i < N; ++i) {
      scanf("%d", &values[i]);
    }
    quick_sort(0, N - 1);
    printf("%d", values[0]);
    for (int i = 1; i < N; ++i) {
      printf(" %d", values[i]);
    }
    printf("\n");
  }
}