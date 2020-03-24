typedef struct sll_node sll_node;
typedef struct bst_node bst_node;
typedef struct avl_node avl_node;
typedef struct dll_node dll_node;
typedef struct graph_node graph_node;
typedef struct graph_list graph_list;

sll_node* sll_new_node(int data);
dll_node* dll_new_node(int data);
bst_node* bst_new_node(int data);
graph_list* graph_create(int);

void sll_print(sll_node* head);
void sll_print_in_reverse(sll_node* head);
void sll_push_at_end(sll_node** head, sll_node** tail, int data);
void sll_push_at_start(sll_node** head, sll_node** tail, int data);
int sll_pop_at_end(sll_node** head, sll_node** tail);
int sll_pop_at_start(sll_node** head, sll_node** tail);
void sll_reverse(sll_node** head);
int sll_push_at_position(sll_node** ,sll_node**, int,int);
int sll_pop_at_position(sll_node**,sll_node**,int);

void dll_print(dll_node* head);
void dll_push_at_end(dll_node** head, dll_node** tail, int data);
void dll_push_at_start(dll_node** head, dll_node** tail, int data);
int dll_pop_at_end(dll_node** head, dll_node** tail);
int dll_pop_at_start(dll_node** head, dll_node** tail);
void dll_push_at_position(dll_node**,dll_node**,int,int);
int dll_pop_at_position(dll_node**,dll_node**,int);

void bst_push(bst_node** Node, int data);
void bst_in_order(bst_node *root);
void bst_pre_order(bst_node *root);
void bst_post_order(bst_node *root);

int avl_height(bst_node *N);
int max(int a, int b);
int avl_get_balance(bst_node *N);
bst_node *avl_new_node(int data);
void avl_right_rotate(bst_node** N);
void avl_left_rotate(bst_node** N);
void avl_push(bst_node** Node, int data);
void swap(int* a, int *b);
void max_heap_up(int* heap, int c );
void max_heap_down(int* heap,int n,int c);
void max_heap_build(int* arr, int n);
void array_print(int* arr, int n);
void max_heap_push(int* heap, int* n, int data);
int max_heap_pop(int* heap, int* n);
void min_heap_up(int* heap, int c );
void min_heap_down(int* heap,int n,int c);
void min_heap_build(int* arr, int n);
void min_heap_push(int* heap, int* n, int data);
int min_heap_pop(int* heap, int* n);
void min_heap_pop_at_position(int*,int*,int);

void bubble_sort(int*, int);
void selection_sort(int*, int);
void insertion_sort(int*, int);
void merge_sort(int*, int,int);
void merge(int*,int,int,int);
void quick_sort(int*, int,int);
int partition(int*, int,int);
void heap_sort(int*,int);


void graph_add_edge(graph_list*, int, int,int);
void graph_print(graph_list*);
void graph_dfs(graph_list*,int,int);
void graph_dfsUTIL(graph_list*,int,int*,int);
void graph_bfs(graph_list*,int,int);
void bfs_print(graph_list*,sll_node*,int*);
void graph_dijkstra(graph_list*,int,int);
void dikjstraUTIL(graph_list*,sll_node**,sll_node**,int*,int,int);
int shortest_dist(sll_node**);
void print_dijkstra(int* ,int,int*);
int set_weight(sll_node*,sll_node*,int*,int);
int set_dist(sll_node**,int);
void set_vertices(sll_node**,int);
int check(sll_node**);
