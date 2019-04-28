void special_in_order (node *root, node *x, int *max, short int *flag) {
	if (root != NULL && *flag == 0) {
		special_in_order(root -> left, x, max, flag);
		if (root == x) {
			*flag = 1;
			return;
		}
		if (root -> key < x -> key && 
			x -> key - root -> key < x -> key - *max) *max = root -> key;
		special_in_order(root -> right, x, max, flag);
	}
	return;
}

int get_requested_value (node *root, node *x) {
	int max = -1;
	short int flag = 0;
	special_in_order(root, x, &max, &flag);
	return max;
}
