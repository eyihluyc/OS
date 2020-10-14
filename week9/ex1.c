#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc <2){
		printf ("please start the program once again specifying parameter - the number of page frames\n");
		return 0;
	}
	int n = atoi(argv[1]);
	FILE *file;
	char* filename = "Lab 09 input.txt";
	file = fopen(filename, "r");
	if (file == NULL){
		printf("Could not open file!");
		return 0;
	}
	int pages[n];
	int age[n];
	for (int i=0; i<n; i++){
		age[i]=0;
		pages[i]=-1;

	}

	int hits=0, misses=0;
	int earliest = 0;
	while (!feof(file)){
		int current=0;
		int is_hit = 0;
		fscanf(file, "%d", &current);
		if (current < 1) continue;
		for (int i=0; i<n; i++){
			age[i]=age[i]>>1;
			if (pages[i]==current){
				age[i] += 2<<8;
				is_hit = 1;
			}
		}
		if (is_hit){
			hits++;
		}
		else{
			int candidate = -1;
			for (int i=0; i<n; i++){
				if (age[earliest] == 0){
					candidate = earliest;
					break;
				}
				earliest++;
				if (earliest == n) earliest = 0;
			}	
			if (candidate == -1){
				int i_oldest = 0;
				int min_age = age[0];
				for (int i=1; i<n; i++){
				//	printf("%d ", age[i]);
					if (age[i] <= min_age){
				//		printf("!");
						i_oldest = i;
						min_age = age[i];
					}
				}
				candidate = i_oldest;
			}
//			printf("%d\n", candidate);
			pages[candidate] = current;
			age[candidate] = 2<<8;
			misses++;
		}
	}
	printf("Hit/miss ratio: %d/%d\n", hits, misses);
	fclose(file);
	return 0;
}
