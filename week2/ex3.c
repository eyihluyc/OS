#include <stdio.h>

int main(int argc, char *argv[]){
	int n;
	if (sscanf(argv[1], "%d", &n) != 1){
		printf("Failed to find input");
		return -1;
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<2*n; j++){
			if (j<n-i || j>n+i)
				putchar(' ');
			else if (3*i == j || 3*i - n*3/4  == j) putchar ('0');
			else putchar('*');
		}
		putchar('\n');
	}
	return 0;
}
