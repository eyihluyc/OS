#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	DIR* dir = opendir("temp");
	int n = 0;
	struct dirent *dp;
	while ((dp = readdir(dir)) != NULL){
		n++;
	}
	(void) closedir(dir);
	

	int* inodes = calloc(n, sizeof(int));
	char** names = calloc(n*n, 256);
	int* counter = calloc(n, sizeof(int));

	int next_available = 0;
	dir = opendir("temp");
	while ((dp = readdir(dir)) != NULL){
		int inode = dp -> d_ino;
		int i=0;
		for (i; i<n; i++){
			if (inodes[i] == inode){
				break;
			}
		}
		if (i == n){
			i = next_available;
			next_available++;
			inodes[i] = inode;
		}
		names[i*n+counter[i]] = dp -> d_name;
		counter[i]++;
		
	}

	for (int i=0; i<n; i++){
		if (counter[i] > 1){
			for (int j=0; j<counter[i]; j++){
				printf("%s ", names[i*n+j]);
			}
			printf("\n");
		}

	}
	(void) closedir(dir);
	return 0;
}
