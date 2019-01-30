#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#define MAX 10000

int main () { 
	freopen("sort.in", "w", stdout);
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	for (int i = 0; i < n; i++) printf("%d ", rand() % (MAX + 1));
	fclose(stdout);
	return 0;
}

