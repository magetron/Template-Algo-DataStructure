#include "stdio.h"

void print_inst(int lvl, char from, char to) {
	printf("Move disc %d from %c to %c.\n", lvl, from, to);
	return;
}

int hanoi (int lvl, char from, char mid, char to) {
	if (lvl == 1) {
		print_inst(lvl, from, to);
		return 0;
	} else {
		hanoi(lvl - 1, from, to, mid);
		print_inst(lvl, from, to);
		hanoi(lvl - 1, mid, from, to);
	}
}

int lvl;
const char from = 'A';
const char mid = 'B';
const char to = 'C';

int main () {
	scanf("%d", &lvl);
	hanoi(lvl, from, mid, to);
	return 0;
}
