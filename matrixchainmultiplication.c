#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "limits.h"

int min (int a, int b) {
    return a > b ? b : a;
}

int matrix_chain_multiplication (int *p, int size) {
    int cp_matrix[size - 1][size - 1];
    for (int i = 0; i < size - 1; i++) cp_matrix[i][i] = 0;
    for (int len = 2; len < size; len++) 
        for (int i = 1; i <= size - 1; i++) {
            int j = i + len - 1;
            cp_matrix[i - 1][j - 1] = INT_MAX;
            for (int k = i; k < j; k++)
                cp_matrix[i - 1][j - 1] = min(cp_matrix[i - 1][j - 1], 
                                        cp_matrix[i - 1][k - 1] + cp_matrix[k][j - 1] 
                                        + p[i - 1] * p[k] * p[j]);
        }
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) printf("%d ", cp_matrix[i][j]);
        printf("\n");
    }
    
    return cp_matrix[0][size - 2];
}

int *chain_generator (int size) {
    srand(time(NULL));
    int *p = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) p[i] = rand() % 100;
    
    for (int i = 0; i < size; i++) printf("%d ", p[i]);
    printf("\n");
    
    return p;
}

int main () {
    printf("%d\n", matrix_chain_multiplication(chain_generator(6), 6));
    return 0;
}
