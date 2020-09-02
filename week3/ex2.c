#include<stdio.h>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}


void bubble_sort(int* arr, int len){
	for (int i=1; i<len; i++){
		for (int j=1; j<len; j++){
			if (*(arr+j) < *(arr+j-1))
				swap (arr+j, arr+j-1);
		}
	}
}

int main(){
	printf("Enter length of array: ");
	int len;
	scanf("%d", &len);
	printf("Enter %d integers: ", len);
	int arr[len];
	for (int i=0; i<len; i++)
		scanf("%d", arr+i);
	bubble_sort(arr, len);
	printf("Sorted array: ");
	for (int i=0; i<len; i++){
		printf("%d ", arr[i]);	
	}
	printf("\n");
	return 0;
}
