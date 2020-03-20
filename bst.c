struct bst_node {
	int data; 
	int height;
	struct bst_node *left;
	struct bst_node *right;
};


bst_node *bst_new_node(int data) {
	bst_node *temp = (bst_node *)malloc(sizeof(bst_node)); 
	temp->data = data; 
	temp->left = temp->right = NULL;
	return temp; 
}

void bst_push(bst_node** Node, int data)  { 
	
	if (*Node == NULL) 
	     (*Node) = bst_new_node(data); 
	else if (data < (*Node)->data) 
		bst_push(&((*Node)->left), data); 
	else 
		bst_push(&((*Node)->right), data);
}

void bst_in_order(bst_node *root) { 
	if (root != NULL) { 
		bst_in_order(root->left); 
		printf("%d ", root->data); 
		bst_in_order(root->right); 
	} 
}
 
void bst_pre_order(bst_node *root) { 
	if (root != NULL) { 
	 printf("%d ", root->data); 
		bst_pre_order(root->left); 
		bst_pre_order(root->right); 
	} 
}
 
void bst_post_order(bst_node *root) { 
	if (root != NULL) { 
		bst_post_order(root->left); 
		bst_post_order(root->right); 
		printf("%d ", root->data); 
	} 
}

