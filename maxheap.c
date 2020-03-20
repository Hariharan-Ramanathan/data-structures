void max_heap_up(int* heap, int c )  {
	if(c == 0)
		return;
	int p = (c-1)/2;
	if(heap[c]>heap[p])
		swap(&heap[c],&heap[p]);
	max_heap_up(heap, p);
}

void max_heap_down(int* heap,int n,int c)  {
  int l = 2*c+1;
  int r = 2*c+2;
  if(l<n) {
		if((r<n) && (heap[r]>heap[l])) {
			if(heap[r]>heap[c])  {
		  	swap(&heap[r],&heap[c]);
		  }
		  max_heap_down(heap,n,r);
		}  	
		else	{
		if(heap[l]>heap[c])  {
		  	swap(&heap[l],&heap[c]);
		  }
		  max_heap_down(heap,n,l);
		}
	}
	else
		return;		
}
void max_heap_build(int* arr, int n)	{
    for (int i = n/2-1; i >= 0; i--) 
        max_heap_down(arr, n, i);
}
  
void max_heap_push(int* heap, int* n, int data)  {
  heap[(*n)++] = data;
  max_heap_up(heap,(*n)-1);
}

int max_heap_pop(int* heap, int* n)  {
	int temp = heap[0];
	heap[0] = heap[(*n)-1];
	(*n)--;
	max_heap_down(heap,*n,0);
	return temp;
}	

