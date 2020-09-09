#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int n;
	pid_t pid = fork();
	if (!pid)
		printf("Hello from parent [%d - %d]\n", getpid(), n);
	else
		printf("Hello from child [%d - %d]\n", getpid(), n);
	return 0;
}
