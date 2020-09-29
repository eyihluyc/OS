#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 21

struct queue{
	int arr[SIZE];
	int head, tail;
};

struct queue* queue_init(){
	struct queue* pqueue = (struct queue*) malloc(sizeof(struct queue));
	pqueue -> head = 0;
	pqueue -> tail = 1;
}

bool is_full(struct queue* pqueue){
	return pqueue -> head == pqueue -> tail;
}

bool is_empty(struct queue* pqueue){
	return !((SIZE + pqueue -> head - pqueue -> tail + 1) % SIZE);
}

void push(struct queue* pqueue, int item){
	pqueue -> arr[pqueue -> head] = item;
	pqueue -> head --;
	if (pqueue -> head == -1) pqueue -> head = SIZE-1;
}

void pull(struct queue* pqueue){
	pqueue -> tail --;
	if (pqueue -> tail == -1) pqueue -> tail = SIZE-1;
}

void print(struct queue* pqueue){
	int tail = pqueue -> tail;
	int head = pqueue -> head;
	printf("BUFFER is: ");
	while ((SIZE + tail - head - 1)%SIZE){
		head ++;
		if (head == SIZE) head = 0;
		printf("%d ", pqueue -> arr[head]);
	}
}


void producer(){
	time_t t;
	srand((unsigned) time(&t));
	while (true){
		int item=(rand()%100);
		printf("%d\n", item);
		sleep(1);
	}	
}


int main(){
	struct queue* pqueue = queue_init();
	producer();
}
