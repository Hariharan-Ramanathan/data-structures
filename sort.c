//include all of your sorting functions
void bubble_sort(int *a,int n){
for(int i=0;i<n;i++){
	for(int j=0;j<n-1;j++){
		if(a[j]>a[j+1]){
			swap(&a[j],&a[j+1]);
		}
	}
}
}

void insertion_sort(int* a,int n){
	for(int i=1;i<n;i++){
		int value=a[i];
		int hole=i;
		while(hole>0 && a[hole-1]>value){
			a[hole]=a[hole-1];
			hole=hole-1;
		}
		a[hole]=value;
	}
}

void selection_sort(int* a,int n){
	for(int i=0;i<n-1;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
				}}
				swap(&a[min],&a[i]);
	}
}

void merge_sort(int* a,int l,int r){
	if(l<r){
		int mid=(l+r)/2;
			merge_sort(a,l,mid);
			merge_sort(a,mid+1,r);
			merge(a,l,mid,r);
	}
}
void merge(int *a,int left,int mid,int right){
	int i=0;
	int j=0;
	int k=left;
	int n1=mid-left+1;
	int n2=right-mid;
		int l[n1];
		int r[n2];
		for(int i=0;i<n1;i++){
			l[i]=a[left+i];
		}
		for(int j=0;j<n2;j++){
			r[j]=a[mid+j+1];
		}
		while(i<n1 && j<n2){
		if(l[i]<=r[j]){
			a[k]=l[i];
			i=i+1;
			k=k+1;
		}else{
			a[k]=r[j];
			j=j+1;
			k=k+1;
		}
	}
	while(i<n1){
		a[k]=l[i];
		i=i+1;
		k=k+1;
	}
	while(j<n2){
		a[k]=r[j];
		k=k+1;
		j=j+1;
	}
}

void quick_sort(int *a,int start,int end){
	if(start<end){
		int p_index=partition(a,start,end);
			quick_sort(a,start,p_index-1);
			quick_sort(a,p_index+1,end);
	}
}
int partition(int* a,int start,int end){
	int pivot=a[end];
	int index=start;
		for(int i=start;i<end;i++){
			if(a[i]<=pivot){
				swap(&a[i],&a[index]);
				index++;
			}
		}	
		swap(&a[index],&a[end]);
		return index;
}

void heap_sort(int* arr,int n){
	while(n!=1){
		swap(&arr[0],&arr[n-1]);
		n--;
		min_heap_down(arr,n,0);
	}

}
