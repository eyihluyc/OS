#include <stdio.h>

int main(){
	FILE *f1 = fopen("ratio_increased.txt", "w");
	for (int i=0; i<1000; i++){
		fprintf (f1, "423 ");
	}
	FILE *f2 = fopen("ratio_decreased.txt", "w");
	for (int i=0; i<1000; i++){
		fprintf (f2, "%d ", i+100);
	}

}
