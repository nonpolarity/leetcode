#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

bool
isHappy(int n)
{
	while (1) {
		int		sum = 0;
		int		digit;
		while (n > 0) {
			digit = n % 10;
			sum += digit * digit;
			n /= 10;

		}
		if (sum == 1)
			return 1;
		if (sum == 4)
			return 0;
		n = sum;
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	int		i = 1;
	while (i) {
		printf("Please input the number:\n");
		scanf("%d", &i);
		if (isHappy(i))
			printf("Happy number!\n");
	}
	return 0;
}
