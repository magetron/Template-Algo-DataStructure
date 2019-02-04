#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_string_length 255

char *strrev (char *str) {
	char *p1, *p2;
	if ( (!str) || (!*str) ) return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;
	}
	return str;
}

char *to_base (int n, int b) {
	char *str = malloc(max_string_length * sizeof(char));
	short int loc = 0;
	int tmp;
	while (n > 0) {
		tmp = n % b;
		if (tmp >= 10) str[loc++] = tmp + 55;
		else str[loc++] = tmp + 48;
		n /= b;
	}
	str[loc++] = '\0';
	return strrev(str);
}

int from_base (char *n, int b) {
	int dec = 0;
	int len = strlen(n);
	int tmp;
	for (int i = 0; i < len; i++) {
		if (n[i] > 64) tmp = n[i] - 55;
		else tmp = n[i] - 48;
		dec = dec * b + tmp;
	}
	return dec;
}
		

int main () {
	int mode;
	printf("1. from base to decimal / 2. from decimal to base\n");
	scanf("%d", &mode);
	if (mode == 1) {
		char *n = malloc(max_string_length * sizeof(char));
		int b;
		scanf("%s%d", n, &b);
		printf("%d\n", from_base(n, b));	
	}
	else if (mode == 2) {
		int n, b;
		scanf("%d%d", &n, &b);
		printf("%s\n", to_base(n, b));
	}
	return 0;
}
