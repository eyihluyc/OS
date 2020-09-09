#include <stdio.h>



void swap (int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int a;
        int b;
	printf("Please, enter two numbers: ");
	scanf ("%d", &a);
	scanf ("%d", &b);
	printf("before swap: a = %d, b = %d\n", a, b);
	swap (&a, &b);
	printf("after swap: a = %d, b = %d\n", a, b);
	return 0;
}

