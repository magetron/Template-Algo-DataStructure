#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct {
    int index;
    char *suffix;
} rotation;

int cmpfunc (const void *x, const void *y) {
    rotation *rx = (rotation *)x;
    rotation *ry = (rotation *)y;
    return strcmp(rx -> suffix, ry -> suffix);
}

int *get_suffix_arr (char *input, int len) {
    rotation suffix[len];
    for (int i = 0; i < len; i++) {
        suffix[i].index = i;
        suffix[i].suffix = input + i;
    }
    
    qsort(suffix, len, sizeof(rotation), cmpfunc);
    
    int *suffix_arr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) suffix_arr[i] = suffix[i].index;
    
    return suffix_arr;
}

char *get_bwt_arr (char *input, int len, int *suffix_arr) {
    char *bwt_arr = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        int j = suffix_arr[i] - 1;
        if (j < 0) j += len;
        bwt_arr[i] = input[j];
    }
    bwt_arr[len] = '\0';
    return bwt_arr;
}

int main () {
    char *input = "appellee";
    int len = strlen(input);
    char *bwt_arr = get_bwt_arr(input, len, get_suffix_arr(input, len));
    printf("%s\n", bwt_arr);
    return 0;
}
