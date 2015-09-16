#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int
climbStairs(int n)
{
	if (n < 2)
		return 1;
	int		Fibn_1 = 1, Fibn_2 = 1, i = 2;
	for (; i <= n; i++) {
		Fibn_1 = Fibn_2 + Fibn_1;
		Fibn_2 = Fibn_1 - Fibn_2;

	}
	return Fibn_1;
}

int
main(int argc, char *argv[])
{
	for (int i = 0; i < 90; i++)
		printf("Solutios for %d are %d\n", i, climbStairs(i));
	return 0;
}
