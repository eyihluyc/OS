#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	printf("Integer = %d\nFloat = %f\nDouble = %f\n",
			i, f, d);
	
	printf("Sizeof Integer = %ld\nSizeof Float = %ld\nSizeof Double = %ld\n",
			sizeof(i), sizeof(f), sizeof(d));
	return 0;
}
