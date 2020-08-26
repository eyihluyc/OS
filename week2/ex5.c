#include <stdio.h>


void first(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<=i; j++){
			putchar('*');
		}
		putchar('\n');
	}
}


void second(int n){
	for (int i=0; i<n/2; i++){
		for (int j=0; j<=i; j++){
			putchar('*');
		}
		putchar('\n');
	}
	for (int i=n/2; i<n; i++){
		for (int j=n-i; j>0; j--){
			putchar('*');
		}
		putchar('\n');
	}
}

void third(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			putchar('*');
		}
		putchar('\n');
	}
}



int main(int argc, char *argv[]){
	int n;
	if (sscanf(argv[1], "%d", &n) != 1){
		printf("Failed to find input");
		return -1;
	}

	int version;
	printf("Please specify version (enter 1, 2, or 3): ");
	scanf("%d", &version);
	switch (version){
		case 1:
			first(n);
			break;
		case 2:
			second(n);
			break;
		case 3:
			third(n);
			break;
	}
	return 0;
}
