int max(int a, int b)	{ 
	return (a > b)? a : b; 
} 

void swap(int* a, int *b)  {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void array_print(int* arr, int n)  {
	for(int i=0; i<n; i++) {
		printf("\n%d ",arr[i]);
	}
	printf("\n");
}

