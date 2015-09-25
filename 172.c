#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int
trailingZeroes(int n)
{
	int		howmanyfives = 0;
	while (n > 1) {
		n /= 5;
		howmanyfives += n;
	}
	return howmanyfives;
}

int
main(int argc, char *argv[])
{
	return 0;
}
