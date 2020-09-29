#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct thread_info {
	pthread_t thread_id;
	int thread_num;
};


static void* show(void* arg){
	struct thread_info *tinfo = arg;
	printf("Hello from thread %d\n", tinfo->thread_num);
}

int main(){
	int N;
	printf("Enter N - number of threads: ");
	scanf("%d", &N);
	struct thread_info* tinfo;
	tinfo = calloc(N, sizeof(struct thread_info));
	
	for (int tnum=0; tnum<N; tnum++){
		tinfo[tnum].thread_num = tnum+1;
		pthread_create(&tinfo[tnum].thread_id, NULL, &show, &tinfo[tnum]);
		printf("Thread %d created\n", tinfo[tnum].thread_num);
	}
	
	for (int tnum=0; tnum<N; tnum++){
		pthread_join(tinfo[tnum].thread_id, NULL);
		printf("Joined with thread %d\n", tinfo[tnum].thread_num);
	}

	
	return 0;
}
