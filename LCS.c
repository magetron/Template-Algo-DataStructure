#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_string_length 256

int max (int a, int b) {
	return a > b ? a : b;
}

int lcs (char *strx, char * stry, int m, int n) {
	int ans[m + 1][n + 1];
	for (int i = 0; i <=m ; i++) 
		for (int j = 0; j <= n; j++) 
			if ( (i == 0) || (j == 0) ) ans[i][j] = 0;
			else if ( strx[i - 1] == stry[j - 1] )
				ans[i][j] = ans[i - 1][j - 1] + 1;
			else ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
	return ans[m][n];
}

int main () {
	char strx[max_string_length];
	char stry[max_string_length];
	fgets(strx, max_string_length, stdin);
	fgets(stry, max_string_length, stdin);
	printf("%d\n", lcs(strx, stry, strlen(strx) - 1, strlen(stry) - 1));
	return 0;
}
