#include <stdio.h>

int main(){
	printf ("This is shell\n");
	char command [123];
	while (1){
		printf(">>>");
		scanf("%123s", command);
		system(command);
	}
	return 0;
}
