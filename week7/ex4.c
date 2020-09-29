#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void* my_realloc(void *oldptr, size_t oldsize, size_t newsize){
	void* newptr = malloc(newsize);
	if (oldsize < newsize)
		memcpy(newptr, oldptr, oldsize);
	else
		memcpy(newptr, oldptr, newsize);

	free (oldptr);
	return newptr;
}

int main(){
	int* a1 = malloc(sizeof(int)*5);
	a1[0] = 10;
	a1[1] = 11;
	a1[2] = 12;
	a1[3] = 13;
	a1[4] = 14;
	a1 = my_realloc(a1, sizeof(int)*5, sizeof(int)*7);
	for (int i=0; i<7; i++){
		//printf("%d ", a1[i]);
		//prints 10 11 12 13 14 0 0
	}
	return 0;
}
