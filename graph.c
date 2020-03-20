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
			if(!visited[p->data])
				printf("%d\n",p->data);
	
		visited[p->data]=1;
		p=p->next;
		}
		bfs_print(g,g->list[temp->data].head,visited);
	}
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
/*
void dijkstraUTIL(graph_list* g,int* visited,int* short_path,int a,int n){
	visited[a]=1;
	printf("Vertex-%d  dist-%d\n",a,short_path[a]);
	sll_node* p=g->list[a].head;
	sll_node* c=g->list[a].path;
	printf("data-%d\n",c->data);	
	
}

void graph_dijkstra(graph_list* g,int a,int v){
	int visited[v];
	int short_path[v];
	for(int i=0;i<v;i++){
		short_path[i]=0;
		visited[i]=0;
	}
	dijkstraUTIL(g,visited,short_path,a,v);
}*/
