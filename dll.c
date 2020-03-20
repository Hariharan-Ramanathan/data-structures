struct dll_node {
 int data;
 dll_node *next;
 dll_node *prev;
};

dll_node* dll_new_node(int data)  { 
 dll_node* temp = malloc(sizeof(dll_node));
 temp->data = data;
 temp->prev = NULL;
 temp->next = NULL;
 return temp;
}

void dll_print(dll_node* head)  { 
 dll_node* p = head;
 while(p!=NULL)  {
  printf("%d  ",p->data);
  p = p->next;
  }
  printf("\n");
}
   
void dll_push_at_end(dll_node** head, dll_node** tail, int data)  { 
   dll_node* new_node = dll_new_node(data);
    
   if((*head) == NULL)  {
    (*head) = new_node;
    (*tail) = (*head);
   } 
   else if((*head)->next == NULL)	{
     new_node->prev = *head;
    (*head)->next = new_node;
    (*tail) = new_node;
   }
   else {
   	new_node->prev = *tail;
   	(*tail)->next = new_node;
   	(*tail) = (*tail)->next;
   }	 
}

void dll_push_at_start(dll_node** head, dll_node** tail, int data)  {
   if((*head) == NULL)  {
    (*head) = dll_new_node(data);
    (*tail) = (*head);
	} 
   else  {
    dll_node* p = dll_new_node(data);
    p->next = (*head);
    (*head) = p;
    }
}
int dll_pop_at_end(dll_node** head, dll_node** tail)  {
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
		(*tail) = (*tail)->prev;
		(*tail)->next = NULL;
	}
	else	{
		res = (*tail)->data;
		(*tail) = (*tail)->prev;
		(*tail)->next = NULL;
		
	}
	return res;
}	
	
int dll_pop_at_start(dll_node** head, dll_node** tail)	{
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
		(*head)->prev = NULL;
	}	
	return res;	 		
}				

void dll_push_at_position(dll_node** head,dll_node** tail,int pos,int data){
	dll_node* newnode=dll_new_node(data);
	int count=0;
	dll_node* temp=*head;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	temp=*head;
	if(pos<=count){
		if(pos==1){
			newnode->next=*head;
			(*head)->prev=newnode;
			*head=newnode;
		}else if(pos==count){
			newnode->prev=*tail;
			(*tail)->next=newnode;
			*tail=newnode;
			}
		else{
			int c=2;
			while(c!=pos){
				temp=temp->next;
				c++;
				//printf("\ntemp value=%d \n",temp->data);
			}
			
			newnode->next=temp->next;
			temp->next->prev=newnode;
			temp->next=newnode;
			newnode->prev=temp;
		}	
	}else{
		printf("Position exceeds list\n");
	}

 }
 
 int dll_pop_at_position(dll_node** head,dll_node** tail,int pos){
	int count=0;
	int res=0;
	dll_node* temp=*head;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	temp=*head;
	if(pos<=count){
		if(pos==1){
			 res=dll_pop_at_start(head,tail);
		}
		else if(pos==count){
			 res=dll_pop_at_end(head,tail);
		}
		else{
			int c=1;
			while(c!=pos){
				temp=temp->next;
				c++;
			}
			temp->next->prev=temp->prev;
			temp->prev->next=temp->next;
			res=temp->data;
			return res;
		}
 }else{
	 printf("Position exceeds list\n");
 }
 }

