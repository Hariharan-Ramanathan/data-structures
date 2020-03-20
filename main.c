#include <stdio.h>
#include <stdlib.h>
#include "dsa.c"

int main()	{
	int n = 4;
	graph_list* g = graph_create(n);
	graph_add_edge(g,0,1,3);
	graph_add_edge(g,0,2,4);
	graph_add_edge(g,1,2,1);
	graph_add_edge(g,2,3,1);
//	graph_add_edge(g,2,0,5);
//	graph_add_edge(g,3,3,5);
//	graph_add_edge(g,4,3);
//	graph_add_edge(g,3,2);

	graph_print(g);
	printf("\nDFS\n");
	graph_dfs(g,0,n);
	printf("\nBFS\n");
	graph_bfs(g,0,n);
//	graph_dijkstra(g,1,n);
}	


/*

#include<stdio.h>
#include<stdlib.h>
#include "dsa.c"

int main(){
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	int* arr=malloc(n*sizeof(int*));
	printf("Enter the values\n");
	for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
	}
	bst_node* try=NULL;
	int i=0;
	while(i!=n){
	bst_push(&(try),arr[i]);
		i++;
	}
	bst_pre_order(try);	
}

#include<stdio.h>
#include<stdlib.h>
#include "dsa.c"

int main(){
	char a;
	int val=0;
	dll_node* head=NULL;
	dll_node* tail=NULL;
	while(a!='q'){
		printf("a)add node at start\nb)add node at end\nc)pop node at start\nd)pop node at end\ne)printf\nf)add at position\ng)pop at position\nq)quit");
		scanf(" %c",&a);
		switch(a){
			case 'a':{
			printf("Enter the data\n");
			scanf("%d",&val);
			dll_push_at_start(&head,&tail,val);
			break;
		}
			case 'b':
			{
			printf("Enter the data\n");
			scanf("%d",&val);
			dll_push_at_end(&head,&tail,val);
			break;	
			}
		
			case 'c':
			{
			dll_pop_at_start(&head,&tail);
			break;	
			}
			case 'd':
			{
			dll_pop_at_end(&head,&tail);
			break;	
			}
			case 'e':
			{
			dll_print(head);
			break;
			}
			case 'f':
			{
			int pos=0;
			printf("Enter the position\n");
			scanf("%d",&pos);
			printf("Enter the data\n");
			scanf("%d",&val);
			dll_push_at_position(&head,&tail,pos,val);
			break;
			}
			
			case 'g':
			{
			int pos=0;
			printf("Enter the position\n");
			scanf("%d",&pos);
			dll_pop_at_position(&head,&tail,pos);
			break;
			}
			default:{
			printf("Enter the correct data\n");
			break;}
		
		
		}
		
	}
	
} 

*/























 
 /*	printf("\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
		printf("Input array: \n");
		array_print(arr, n);
		insertion_sort(arr, n); 
		printf("after insertion_sort: \n"); 
		array_print(arr, n);
	
	printf("\n");
	
	int a[] = {64, 34, 25, 12, 22, 11, 90}; 
		printf("Input array: \n");
		array_print(a, n);
		bubble_sort(a, n); 
		printf("after bubble_sort: \n"); 
		array_print(a, n);
	
	printf("\n");
	
	int ar[] = {64, 34, 25, 12, 22, 11, 90}; 
		printf("Input array: \n");
		array_print(ar, n);
		selection_sort(ar, n); 
		printf("after selection_sort: \n"); 
		array_print(ar, n);
	
	printf("\n");
	
	int arrr[] = {64, 34, 25, 12, 22, 11, 90}; 
		printf("Input array: \n");
		array_print(arrr, n);
		merge_sort(arrr,0, n-1); 
		printf("after merge_sort: \n"); 
		array_print(arrr, n);	
	
	printf("\n");
	
	int aarr[] = {64, 34, 25, 12, 22, 11, 90}; 
		printf("Input array: \n");
		array_print(aarr, n);
		quick_sort(aarr, 0,n-1); 
		printf("after quick_sort: \n"); 
		array_print(aarr, n);
		
		//sll node
		sll_node* head=NULL;
		sll_node* tail=NULL;
		
		while(1){
		
		printf("\na.new_node/add node at end\nb.print\nc.print in reverse\nd.push at start\ne.pop at start\nf.pop at end\ng.reverse sll\nh.push_at_position\ni.pop at position\nq.quit\n");
		char c;
		scanf("\n%c",&c);
		if(c=='q'){
			break;
		}
		else{
			switch(c){

				case 'a':{
				int a;
				printf("Enter the value");
				scanf("%d",&a);
				sll_push_at_end(&head,&tail,a);
				break;}
				
				case 'b':
				sll_print(head);
				break;
				
				case 'c':
				sll_print_in_reverse(head);
				break;
				
				case 'd':{
				int a;
				printf("Enter the value");
				scanf("%d",&a);
				sll_push_at_start(&head,&tail,a);
				break;}
				
				case 'e':
				sll_pop_at_start(&head,&tail);
				break;
				
				case 'f':
				sll_pop_at_end(&head,&tail);
				break;
				
				case 'g':
				sll_reverse(&head);
				break;
				
				case 'h':{
				int v;
				int p,n;
				printf("Enter the position");
				scanf("%d",&p);
				printf("Enter the value");
				scanf("%d",&n);
				v=sll_push_at_position(&head,&tail,p,n);
				printf("\n%d Value added",v);
				break;
				}
				
				case 'i':{
				int v;
				int p;
				printf("Enter the position");
				scanf("%d",&p);
				v=sll_pop_at_position(&head,&tail,p);
				printf("\n%d position removed",v);
				break;
				}
				
				
				default:printf("Check the data entered");
			}
		}
		
		}
		
		
		//binary search tree
		
		bst_node* root=NULL;
		while(1){
			printf("\na.To add value\nq.stop\n");
			char c;
			scanf(" %c",&c);
			if(c=='q'){
				break;
			}
			else{
				printf("Enter the value needed\n");
				int a;
				scanf("%d",&a);
				bst_push(&root,a);
			}
			
		}

			bst_in_order(root);
			//bst_pre_order(root);
			//bst_post_order(root);		


					// min heap 
								// complete heap:- if we represent the tree in an array and if there is no any missing element then it is called as completeheap;
								// full heap :- if the tree contains 2^(h+1)-1 nodes - h is the height of the tree starting from 0;

				int n;
				printf("\nEnter the number of element\n");
				scanf("%d",&n);
				int arr[n];
				printf("\nEnter the elements\n");
				for(int i=0;i<n;i++){
					scanf("%d",&arr[i]);
				}
				min_heap_build(arr,n);
				
				
				
				while(1){
					char c;
					printf("\na.push\nb.pop\nc.print\nd.delete at position\ne.heap_sort\nq.quit\n");
					scanf(" %c",&c);
					if(c=='q'){break;}
					switch(c){
						case 'a':{
							int a;
						printf("\nEnter the data\n");
						scanf("%d",&a);
						min_heap_push(arr,&n,a);
						break;
						}
						case 'b':{
							min_heap_pop(arr,&n);
							break;
						}
						case 'c':
						{
							printf("\nafter min heap\n");
								for(int i=0;i<n;i++){
									printf("\n%d",arr[i]);
								}
							break;
						}
						case 'd':
						{
							array_print(arr,n);
							break;
						}
						case 'e':
						{
							heap_sort(arr,n);
							array_print(arr,n);
							break;
						}
						
					}
				}
				//graph
	
	printf("\nEnter the number of vertices");
	int input;
	scanf("%d",&input);
	
	struct graph* ggraph=create_graph(input);
	graph_add_edge(ggraph,0,1);
	graph_add_edge(ggraph,0,4);
	graph_add_edge(ggraph,1,2);
	graph_add_edge(ggraph,1,3);
	graph_add_edge(ggraph,1,4);
	graph_add_edge(ggraph,2,3);
	graph_add_edge(ggraph,3,4);
	
	graph_print_graph(ggraph);
	
	return 0;
}
		
				
*/
