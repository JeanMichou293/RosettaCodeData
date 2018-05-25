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
    int n = byte_cnt / sizeof a[0] + 1;
    
    // Debug
    //printf("byte_cnt=%d, n=%d, sizeof(a)=%d\n", byte_cnt, n, sizeof(a));
    
    bubble_sort(a, n);
	
    return 0;
}
