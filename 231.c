#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool
isPowerOfTwo(int n)
{
	while (n > 1 & n % 2 == 0)
		n = n >> 1;
	return (n == 1);
}

int
main(int argc, char *argv[])
{
	//int		i = 2147483646;
	int		i = 3;
	printf("the number %d:%d\n", i, isPowerOfTwo(i));
	return 0;
}
