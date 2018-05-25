#include <stdio.h>
#include <unistd.h>

#define INPUT_SIZE 65536

void quicksort(int *A, int len);

int main (void) {
  int a[INPUT_SIZE / sizeof(int)];
  int byte_cnt = read(STDIN_FILENO, a, INPUT_SIZE);
  int n = byte_cnt / sizeof a[0] + 1;

  /*int i;
  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");*/

  quicksort(a, n);

  /*for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");*/

  return 0;
}

void quicksort(int *A, int len) {
  if (len < 2) return;

  int pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (A[i] < pivot) i++;
    while (A[j] > pivot) j--;

    if (i >= j) break;

    int temp = A[i];
    A[i]     = A[j];
    A[j]     = temp;
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}
