#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX_STRING_LENGTH 255

char *read_string () {
    char *a = malloc(sizeof(char) * MAX_STRING_LENGTH);
    fgets(a, MAX_STRING_LENGTH, stdin);
    return a;
}

int min (int a, int b) {
    return a > b ? b : a;
}

int min3 (int a, int b, int c) {
    return min(min(a, b), c);
}

int edit_distance (char *a, char *b) {
    int len_a = strlen(a) - 1;
    int len_b = strlen(b) - 1;
    int d_matrix[len_a + 1][len_b + 1];
    for (int i = 0; i < len_a + 1; i++) d_matrix[i][0] = i;
    for (int i = 0; i < len_b + 1; i++) d_matrix[0][i] = i;
    for (int i = 1; i < len_a + 1; i++) {
        
        for (int j = 1; j < len_b + 1; j++) if (a[i - 1] != b[j - 1])
            d_matrix[i][j] = min3(d_matrix[i - 1][j] + 1, 
                                    d_matrix[i - 1][j - 1] + 1,
                                    d_matrix[i][j - 1] + 1);
        else d_matrix[i][j] = d_matrix[i - 1][j - 1]; 
        
        for (int k = 0; k < len_a + 1; k++) {
            for (int l = 0; l < len_b + 1; l++) printf("%d ", d_matrix[k][l]);
            printf("\n");
        }
    }    
    return d_matrix[len_a][len_b];
}

int main () {
    char *a = read_string();
    char *b = read_string();
    printf("%d\n", edit_distance(a, b));
    return 0;
}
