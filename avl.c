int avl_height(bst_node *N)	{ 
	if (N == NULL)
		return 0; 
	return N->height;
} 

int avl_get_balance(bst_node *N)	{ 
	if (N == NULL) 
		return 0; 
	return avl_height(N->left) - avl_height(N->right); 
} 

bst_node *avl_new_node(int data) { 
	bst_node *temp = (bst_node *)malloc(sizeof(bst_node)); 
	temp->data = data;
	temp->height = 1;
	temp->left = temp->right = NULL;
	return temp; 
} 

void avl_right_rotate(bst_node** N)	{ 
    bst_node *Nl = (*N)->left;  
    bst_node *Nlr = Nl->right; 
    Nl->right = (*N); 
    (*N)->left = Nlr;
    (*N) = Nl;
  
    Nl->height = max(avl_height(Nl->left), avl_height(Nl->right))+1;
    (*N)->height = max(avl_height((*N)->left), avl_height((*N)->right))+1;  
} 
  
void avl_left_rotate(bst_node** N)	{ 
    bst_node *Nr = (*N)->right; 
    bst_node *Nrl = Nr->left; 
    Nr->left = (*N);
    (*N)->right = Nrl;
    (*N) = Nr;
  
    Nr->height = max(avl_height(Nr->left), avl_height(Nr->right))+1; 
    (*N)->height = max(avl_height((*N)->left), avl_height((*N)->right))+1;   
}

void avl_push(bst_node** Node, int data)  { 
	if (*Node == NULL) 
	     (*Node) = avl_new_node(data); 
	else if (data < (*Node)->data) 
		avl_push(&((*Node)->left), data); 
	else 
		avl_push(&((*Node)->right), data);
		
  (*Node)->height = 1 + max(avl_height((*Node)->left), avl_height((*Node)->right)); 
  int balance = avl_get_balance(*Node); 

  if (balance > 1 && data < (*Node)->left->data)  {
      avl_right_rotate(Node);
  }    
  if (balance < -1 && data > (*Node)->right->data) {
      avl_left_rotate(Node); 
  }
  if (balance > 1 && data > (*Node)->left->data)
  { 
      avl_left_rotate(&((*Node)->left)); 
      avl_right_rotate(Node); 
  } 
  if (balance < -1 && data < (*Node)->right->data) 
  { 
      avl_right_rotate(&((*Node)->right)); 
      avl_left_rotate(Node);
  } 
}

