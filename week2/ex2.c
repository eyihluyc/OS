#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[256];

	printf("String to reverse: ");
	scanf ("%s", input);
	int i;
	for (i = strlen(input)-1; i >= 0; i--){
		if(input[i] != '\n')
			putchar(input[i]);
	}
	return 0;
}
