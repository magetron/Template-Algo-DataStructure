#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

int max (int a, int b) {
	return (a > b) ? a : b;
} 


int lcs (char *x, char *y, int len_x, int len_y) {
	int len[len_x + 1][len_y + 1];
	for (int i = 0; i <= len_x; i++) 
		for (int j = 0; j <= len_y; j++)
			if ((i == 0) || (j == 0)) len[i][j] = 0;
			else if (x[i - 1] == y[j - 1]) len[i][j] = len[i - 1][j - 1] + 1;
			else len[i][j] = max(len[i - 1][j], len[i][j - 1]);
	
	int len_lcs = len[len_x][len_y];
	char *lcs = malloc(sizeof(char) * (len_lcs + 1));
	lcs[len_lcs] = '\0';
	int i = len_x;
	int j = len_y;
	while ((i > 0) || (j > 0)) 
		if (x[i - 1] == y[j - 1]) {
			lcs[len_lcs - 1] = x[i - 1];
			i--;
			j--;
			len_lcs--;
		}
		else if (len[i - 1][j] > len[i][j - 1]) i--; else j--;
	for (int i = 0; i < len[len_x][len_y]; i++) printf("%c", lcs[i]);
	return len[len_x][len_y];
}

int main () {
	char x[] = "Hello!";
	char y[] = "Hello World!";
	int len_x = strlen(x);
	int len_y = strlen(y);
	clock_t begin = clock();	
	printf("\n%d", lcs(x, y, len_x, len_y));
	clock_t end = clock();
	printf("\ntime = %lf s", (double)(end - begin) * 1000 / CLOCKS_PER_SEC);
	return 0;
}


