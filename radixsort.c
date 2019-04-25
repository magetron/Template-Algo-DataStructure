#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *generate_arr (int size) {
    srand(time(NULL));
    int *a = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) a[i] = rand() % 1000;
    for (int i = 0; i < size; i++) printf("%d ", a[i]);
    printf("\n");
    return a;
}


int *radix_sort (int *a, int size) {
    int bin[10][100];
    int max = 0; 
    for (int i = 0; i < size; i++) 
        if (max < a[i]) max = a[i];
    int digits = 0;
    while (max > 0) {
        digits++;
        max /= 10;
    }
    for (int i = 0; i < digits; i++) {
        memset(bin, 0, sizeof(bin));
        int divisor = 1;
        for (int j = 0; j < i; j++) divisor *= 10;
        for (int j = 0; j < size; j++) {
            int num = a[j] / divisor % 10;
            bin[num][0]++;
            bin[num][bin[num][0]] = a[j];
        }
        int c = 0;
        for (int j = 0; j < 10; j++) 
            for (int k = 1; k <= bin[j][0]; k++) {
                  a[c] = bin[j][k];
                  c++;
            }
    }
    return a;
}


int main () {
    int *sorted_arr = radix_sort(generate_arr(10), 10);
    for (int i = 0; i < 10; i++) printf("%d ", sorted_arr[i]);
    return 0;
}
