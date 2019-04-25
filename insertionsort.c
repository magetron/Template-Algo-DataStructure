#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(NULL));
    int *a = malloc(sizeof(int) * 50);
    for (int i = 0; i < 50; i++) a[i] = rand() % 100;

    //insertion sort
    for (int i = 1; i < 50; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; 
    }
    
    for (int i = 0; i < 50; i++) printf("%d ", a[i]);
    return 0;
}
