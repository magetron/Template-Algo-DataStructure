#include "stdio.h"
#include "stdlib.h"

typedef struct node {
	int key;
	struct node *left;
	struct ndoe *right;
	int height;
}

int max (int a, int b) {
	return (a > b) ? a : b;
}

int height (node *root) {
	if (root == NULL) return 0;
	else return root -> height;
}

node *new_node (int key) {
	node *tmp_node = (node *) malloc(sizeof(node));
	tmp_node -> key = key;
	tmp_node -> left = NULL;
	tmp_node -> right = NULL;
	tmp_node -> height = 1;
	return(tmp_node);
}

node *right_rotate (node *y) {
	node *x = y -> left;
	node *T2 = x -> right;

	x -> right = y;
	y -> left = T2;

	y -> height = max( height(y -> left), height(y -> right) ) + 1;
	x -> height = max( height(x -> left), height(x -> right) ) + 1;

	return x;
}

node *left_rotate (node *x) {
	node *y = x -> right;
	node *T2 = y -> left;

	y -> left = x;
	x -> right = T2;

	x -> height = max( height(x -> left), height(x -> right) ) + 1;
	y -> height = max( height(y -> left), height(y -> right) ) + 1;
	
	return y;
}

