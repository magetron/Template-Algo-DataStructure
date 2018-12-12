#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define max_children 20

typedef struct node {
	int key;
	int number_child;
	struct node *children[max_children];
	struct node *parent;
} node;

node *create_tree (int data) {
	node *tmp = malloc(sizeof(node));
	tmp -> key = data;
	tmp -> number_child = 0;
	tmp -> parent = NULL;
	memset(tmp -> children, 0, sizeof(tmp -> children));
	return tmp;
}

void add_node_under (node *root, int data) {
	node *tmp = malloc(sizeof(node));
	tmp -> key = data;
	tmp -> parent = root;
	tmp -> number_child = 0;
	root -> children[root -> number_child] = tmp;
	root -> number_child ++;
}

node *search_node_by_key_and_depth (node *root, int cur_depth, int key, int depth) {
	printf("key = %d, depth = %d\n", root -> key, cur_depth);
	if ((root -> key == key) && (cur_depth == depth)) return root;
	else if (cur_depth < depth) {
		node *tmp;
		for (int i = 0; i < root -> number_child; i++) {
			tmp = search_node_by_key_and_depth(root -> children[i], cur_depth + 1, key, depth);
			if (tmp != NULL) return tmp;
		}
		return NULL;
	}
	else if (cur_depth == depth) return NULL;
}

	
void print_tree (node *root) {
	printf("%d ", root -> key);
	for (int i = 0; i < root -> number_child; i++) print_tree(root -> children[i]);
}

int main () {
	node *root = NULL;
	root = create_tree(0);
	add_node_under(root, 1);
	add_node_under(root, 2);
	add_node_under(root -> children[0], 50);
	add_node_under(root -> children[1], 55);
	printf("found = %d\n", search_node_by_key_and_depth(root, 0, 55, 2) -> key);
	print_tree(root);
}


