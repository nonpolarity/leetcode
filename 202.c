#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

bool
isHappy(int n)
{
	int		hash       [810];
	memset(hash, 0, sizeof(hash));
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
		if (hash[sum])
			return 0;
		hash[sum] = 1;
		n = sum;
	}
	return 0;
}

int
main(int argc, char *argv[])
{
	return 0;
}
