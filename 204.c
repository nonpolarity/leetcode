#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countPrimes(int n)
{
	if (n <= 2)
		return 0;
	// Fuck, Count the number of prime numbers LESS than a non-negative number, n.
	n = n - 1;
	if (!n % 2)
		n = n - 1;
	int count = (n - 1) / 2;
	int base = 3;
	char *list = malloc(sizeof(char) * count);
	memset(list, 1, sizeof(char) * count);

	int i = 0;
	int p, np;

	do {
		p = i * 2 + base;
		np = (p * p - base) / 2;
		while (np <= count) {
			list[np] = 0;
			np += p;
		}
		while (!list[++i]) ;
	}
	while (p * p <= n);

	//Do not forget that 2 is prime!!!
	int num = 1;

	for (i = 0; i < count; i++) {
		if (list[i]) {
			printf("%d\n", i * 2 + base);
			num++;
		}
	}
	free(list);
	return num;
}

int main(int argc, char *argv[])
{
	int n = 10000;
	printf("count:%d\n", countPrimes(n));
	return 0;
}
