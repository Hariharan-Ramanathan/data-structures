struct graph_node	{
	sll_node* head;
	sll_node* tail;
	sll_node* weightHead;
	sll_node* weightTail;
};
struct graph_list	{
	int V;
	graph_node* list;
};

graph_list* graph_create(int n)	{
	graph_list* g = malloc(sizeof(graph_list));
	g->list = malloc(sizeof(graph_node)*n);
	for(int i=0; i<n; i++)	{
		g->list[i].head = NULL;
		g->list[i].tail = NULL;
		g->list[i].weightHead=NULL;
		g->list[i].weightTail=NULL;
	}
	g->V = n;
	return g;
}

void graph_add_edge(graph_list* g, int s, int t,int weight)	{
	sll_push_at_end(&(g->list[s].head),&(g->list[s].tail),t);
	sll_push_at_end(&(g->list[s].weightHead),&(g->list[s].weightTail),weight);
}

void graph_print(graph_list* g)	{
	for(int i=0; i<g->V; i++)	{
		printf("vertex %d ->  ",i);
		sll_print(g->list[i].head);	
		printf("weight %d ->  ",i);
		sll_print(g->list[i].weightHead);	
	}
}

void graph_dfsUTIL(graph_list* g,int a,int* visited,int n){
	sll_node* p=g->list[a].head;
	printf("%d\n",a);
	visited[a]=1;
	
	while(p!=NULL){
		a=p->data;
		if(!visited[a])
			graph_dfsUTIL(g,a,visited,n);
		p=p->next;
	}
}

void graph_dfs(graph_list* g,int a,int V){
	int visited[V];
	for(int i=0;i<V;i++){
		visited[i]=0;
	}
	graph_dfsUTIL(g,a,visited,V);
}

void bfs_print(graph_list* g,sll_node* temp,int* visited){
	if(temp!=NULL){
		sll_node* p=temp;
		while(p!=NULL){
			if(!visited[p->data]){
				printf("%d\n",p->data);
			}	
		visited[p->data]=1;
		p=p->next;
		}
		while(temp!=NULL){
			bfs_print(g,g->list[temp->data].head,visited);
			temp=temp->next;
		}}
}
void graph_bfs(graph_list* g,int a,int n){
	int visited[n];	
	for(int i=0;i<n;i++){
	visited[i]=0;
	}
	printf("%d\n",a);
	visited[a]=1;
		bfs_print(g,g->list[a].head,visited);

}

int shortest_dist(sll_node** head){
	int ans=0;
	int min=9999;
	int count=0;
	sll_node* dist=*head;
	while(dist!=NULL){
		if(dist->data<min){
			min=dist->data;
			ans=count+1;
		}
		dist=dist->next;
		count++;
	}

return ans;	
}

int set_dist(sll_node** head,int n){
	int ans=0;
	int val=1;
	while(val!=n){
		*head=(*head)->next;
		val++;
	}
return (*head)->data;	
}
void set_vertices(sll_node** head,int n){
	int val=1;
	while(val!=n){
		*head=(*head)->next;
		val++;
	}
}

int set_weight(sll_node* head,sll_node* p,int* weight,int prev_weight){
	if((head->data +prev_weight) < weight[p->data])
		weight[p->data]=(head->data+prev_weight);
return (head->data + prev_weight);
}
int check(sll_node** head){
	int ans=1;
	int len=0;
	int count=0;
	sll_node* temp=*head;
	while((*head)!=NULL){
		*head=(*head)->next;
		len++;
	}
	*head=temp;
	while((*head)!=NULL){
		if((*head)->data==9999)
			count++;
		*head=(*head)->next;
	}
	*head=temp;
	if(count==len)
		ans=0;
//	printf("check=%d\ncount=%d\nlen=%d\n",ans,count,len);
return ans;
}

void dijkstraUTIL(graph_list* g,sll_node** p,sll_node** dist,int* visited,int* weight,int a,int begin){
	if((*p)!=NULL){
		if(visited[begin]!=1){
		visited[begin]=1;
			sll_node* temp=*p;
			sll_node* temp1=*dist;
				while(check(dist)){
					*dist=temp1;
					*p=temp;
					int num=shortest_dist(dist);
					int min=set_dist(dist,num);
					set_vertices(p,num);
					int low=set_weight(*dist,*p,weight,a);
					(*dist)->data=9999;
					(*dist)=temp1;
					dijkstraUTIL(g,&(g->list[(*p)->data].head),&(g->list[(*p)->data].weightHead),visited,weight,low,(*p)->data);
				}	
		}	
	}
}

void print_dijkstra(int* weight,int n,int* visited){
	weight[0]=0;
	printf("Vertex  Shortest distance\n	 from source\n");
	for(int i=0;i<n;i++){
		printf("  %d              %d",i,weight[i]);
		printf("\n");
		printf("\n");
		}
	}
void graph_dijkstra(graph_list* g,int a,int v){
	int visited[v];
	int weight[v];
	for(int i=0;i<v;i++){
		visited[i]=0;
		weight[i]=9999;
	}
	dijkstraUTIL(g,&(g->list[a].head),&(g->list[a].weightHead),visited,weight,0,0);
	print_dijkstra(weight,v,visited);
}

