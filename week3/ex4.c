#include <stdio.h>


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int p, int r){
	int x = arr[r];
	int i = p-1;
	for (int j=p; j<r; j++){
		if (arr[j] <= x){
			i++;
			swap(arr+i, arr+j);
		}
	}	
	i++;
	swap(arr+i, arr+r);
	return i;
}


void quicksort(int* arr, int p, int r){
	if (p < r){
		int q = partition (arr, p, r);
		quicksort(arr, p, q-1);
		quicksort(arr, q+1, r);
	}
}


int main(){
	int n;
	printf("This is quicksort implementation.\nnumber of elements of array: ");
	scanf("%d", &n);
	printf("please enter %d integers: ", n);
	int arr[n];
	for (int i=0; i<n; i++)
		scanf("%d", arr+i);
	quicksort(arr, 0, n-1);
	printf("sorted array: ");
	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
