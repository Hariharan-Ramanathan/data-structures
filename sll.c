struct sll_node {
 int data;
 sll_node *next;
};



sll_node* sll_new_node(int data)  {  
 sll_node* temp = malloc(sizeof(sll_node));
 temp->data = data;
 temp->next = NULL;
 return temp;
}

void sll_print(sll_node* head)  { 
 sll_node* p = head;
 while(p!=NULL)  {
  printf("%d ",p->data);
  p = p->next;
  }
  printf("\n");
}
   	
void sll_print_in_reverse(sll_node* head)     
{ 
    if (head == NULL) 
     return; 
    sll_print_in_reverse(head->next); 
    printf("%d  ",head->data); 
} 
   
void sll_push_at_end(sll_node** head, sll_node** tail, int data)  { 
   sll_node* new_node = sll_new_node(data); 
    
   if((*head) == NULL)  {
    (*head) = new_node;
    (*tail) = (*head);
   } 
   else if((*head)->next == NULL)	{
    (*head)->next = new_node;
    (*tail)->next = (*head)->next;
    (*tail) = (*tail)->next;
   }
   else {
   	(*tail)->next = new_node;
   	(*tail) = (*tail)->next;
   }	 
}

void sll_push_at_start(sll_node** head, sll_node** tail, int data)  {
   if((*head) == NULL)  {
    (*head) = sll_new_node(data);
    (*tail) = (*head);
   } 
   else  {
    sll_node* p = sll_new_node(data);
    p->next = (*head);
    (*head) = p;
    }
}


int sll_pop_at_end(sll_node** head, sll_node** tail)  {
	int res = 0;
	if(*head == NULL) {
	
	}	
	else if(*head == *tail)	{
		res = (*head)->data;
		(*head) = NULL;
		(*tail) = NULL;
	}
	else if((*head)->next == (*tail))  {
		res = (*tail)->data;
		(*head)->next = NULL;
		(*tail) = (*head);
	}
	else	{
		res = (*tail)->data;
		sll_node* p = (*head);
		while(p->next->next != NULL)
			p = p->next;
		(*tail) = p;
		(*tail)->next = NULL;	
	}
	return res;
}	
	
int sll_pop_at_start(sll_node** head, sll_node** tail)	{
	int res = 0;
	if((*head) == NULL)	{
	}	
	else if(*head == *tail)	{
		res = (*head)->data;
		(*head) = NULL;
		(*tail) = NULL;
	}
	else  {
		res = (*head)->data;
		(*head) = (*head)->next;
	}	
	return res;	 		
}				
	
void sll_reverse(sll_node** head)  {
	sll_node* currn = (*head); 
	sll_node* prevn = NULL; 
	sll_node* nextn = NULL; 
	while(currn != NULL) 
	{ 
		nextn = currn->next; 
		currn->next = prevn; 
		prevn = currn; 
		currn = nextn; 
	} 
	(*head) = prevn;
}

int sll_push_at_position(sll_node** head,sll_node** tail,int p,int n){
	sll_node* temp=*head;
	sll_node* new_node=sll_new_node(n);
	int count=0;
	while(count!=p-2){
		temp=temp->next;
		count++;
	}
	new_node->next=temp->next;
	temp->next=new_node;
	
	return new_node->data;
	
}

int sll_pop_at_position(sll_node** head,sll_node** tail,int p){
	sll_node* temp=*head;
	int count=1;
	if(p==1)
		sll_pop_at_start(head,tail);
	else{
	while(count!=p-1){
		temp=temp->next;
		count++;
	}}
	temp->next=temp->next->next;
	return p;
	
}

