#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "limits.h"

void print_parenthesis (int i, int j, int **bracket, int *n) {
    if (i == j) {
        printf("A%d", (*n)++);
        return;
    }
    printf("(");
    print_parenthesis(i, bracket[i - 1][j - 1], bracket, n);
    print_parenthesis(bracket[i - 1][j - 1] + 1, j, bracket, n);
    printf(")");
}

int matrix_chain_multiplication (int *p, int size) {
    int **bracket = malloc(sizeof(int *) * (size - 1));
    for (int i = 0; i < size - 1; i++) bracket[i] = malloc(sizeof(int) * (size - 1));
    int cp_matrix[size - 1][size - 1];
    for (int i = 0; i < size - 1; i++) cp_matrix[i][i] = 0;
    for (int len = 2; len < size; len++) 
        for (int i = 1; i <= size - len + 1; i++) {
            int j = i + len - 1;
            cp_matrix[i - 1][j - 1] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = cp_matrix[i - 1][k - 1] + cp_matrix[k][j - 1] 
                    + p[i - 1] * p[k] * p[j];
                if (cp_matrix[i - 1][j - 1] > cost) {
                    cp_matrix[i - 1][j - 1] = cost;
                    bracket[i - 1][j - 1] = k;
                }
            }    
        }
    
    int n = 1;
    print_parenthesis(1, size - 1, (int **)bracket, &n);
    printf("\n");
    
    free(bracket);
    free(p);
    
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
