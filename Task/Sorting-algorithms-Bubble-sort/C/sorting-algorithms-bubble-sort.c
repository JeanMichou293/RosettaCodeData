#include <stdio.h>
#include <unistd.h>

#define INPUT_SIZE 65536

void bubble_sort (int *a, int n) {
    int i, t, s = 1;
    while (s) {
        s = 0;
        for (i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                s = 1;
            }
        }
    }
}

int main () {
    int a[INPUT_SIZE / sizeof(int)];
    int byte_cnt = read(STDIN_FILENO, a, INPUT_SIZE);
    
    //int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    //int n = sizeof a / sizeof a[0];
    int n = byte_cnt / sizeof a[0] + 1;
    
    // Debug
    printf("byte_cnt=%d, n=%d, sizeof(a)=%d\n", byte_cnt, n, sizeof(a));
    
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    bubble_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    return 0;
}
