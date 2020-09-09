#include <stdio.h>

int main(){
	printf ("This is shell\n");
	char command [123];
	while (1){
		printf(">>>");
		fgets(command, 123, stdin);
		system(command);
	}
	return 0;
}
