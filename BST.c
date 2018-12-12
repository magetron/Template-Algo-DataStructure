#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} node;

node *new_node (int data) {
	node *tmp_node = (node *)malloc(sizeof(node));
	tmp_node -> key = data;
	tmp_node -> left = NULL;
	tmp_node -> right = NULL;
	return tmp_node;
}

node *add_node (node *cur_node, int data) {
	if (cur_node == NULL) return new_node(data);
	else if (data < cur_node -> key) {
		cur_node -> left = add_node(cur_node -> left, data);
		return cur_node;
	}
	else if (data > cur_node -> key) {
		cur_node -> right = add_node(cur_node -> right, data);
		return cur_node;
	}
}

void in_order (node *cur_node) {
	if (cur_node != NULL) {
		in_order(cur_node -> left);
		printf("%d ",cur_node -> key);
		in_order(cur_node -> right);
	}
	return;
}

node *min_value_from_node(node *root) {
	node *cur_node = root;
	while (cur_node -> left != NULL) cur_node = cur_node -> left;
	return cur_node;
}

node *delete_node (node *root, int data) {
	if (root == NULL) return root;
	if (data < root -> key) root -> left = delete_node(root -> left, data);
	else if (data > root -> key) root -> right = delete_node(root->right, data);
	else if (data == root -> key) {
		if ((root -> left == NULL) && (root -> right == NULL)) {
			free(root);
			return NULL;
		}
		else if (root -> left == NULL) {
			node *tmp = root -> right;
			free(root);
			return tmp;
		}
		else if (root -> right == NULL) {
			node *tmp = root -> left;
			free(root);
			return tmp;
		} else {
			node* tmp = min_value_from_node(root -> right);
			root -> key = tmp -> key;
			root -> right = delete_node(root -> right, root -> key);
			return root;
		}
	}
}

int main () {
	node *root = NULL;
	root = add_node(root, 7);
	add_node(root, 5);
	add_node(root, 4);
	add_node(root, 2);
	add_node(root, 11);
	add_node(root, 8);
	add_node(root, 17);
	in_order(root);
	printf("\n");
	delete_node(root, 11);
	in_order(root);
	printf("\n");
	delete_node(root, 8);
	delete_node(root, 5);
	in_order(root);
	return 0;
}

